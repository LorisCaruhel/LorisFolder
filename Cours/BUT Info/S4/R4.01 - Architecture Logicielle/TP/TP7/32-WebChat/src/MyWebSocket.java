import java.io.IOException;
import java.io.Writer;
import java.util.Hashtable;
import java.util.Map;

import jakarta.json.Json ;
import jakarta.json.JsonObject ;
import jakarta.json.JsonWriter ;

import jakarta.websocket.CloseReason;
import jakarta.websocket.OnClose;
import jakarta.websocket.OnError;
import jakarta.websocket.OnMessage;
import jakarta.websocket.OnOpen;
import jakarta.websocket.Session;
import jakarta.websocket.server.PathParam;
import jakarta.websocket.server.ServerEndpoint;
import jakarta.websocket.server.ServerEndpointConfig;

@ServerEndpoint(value = "/WebSocket/{username}", configurator = MyWebSocket.EndpointConfigurator.class)
public class MyWebSocket {
  /** Singleton. */
  private static MyWebSocket s_instance = new MyWebSocket();

  /**
   *	Accesseur statique.
   *	@return Le singleton. 
   */
  public static MyWebSocket getInstance() {
    return MyWebSocket.s_instance;
  }

  /**
   *	Permet de ne pas avoir une instance différente par client.
   *	ProjectFactory est donc gérer en "singleton" et le configurateur utilise ce singleton. 
   */
  public static class EndpointConfigurator extends ServerEndpointConfig.Configurator {
    @Override 
    @SuppressWarnings("unchecked")
    public <T> T getEndpointInstance(Class<T> _endpointClass) {
      return (T) s_instance ;
    }
  }

  /**
   *	Constructeur.
   */
  private MyWebSocket() { }

  /**
   *	Réagit à l'ouverture de la connextion.
   *	@param _session La session.
   *	@param _username Le nom d'utilisateur.
   *	@throws IOException
   */
  @OnOpen
  @SuppressWarnings("unchecked")
  public void onOpen(Session _session, @PathParam("username") String _username) throws IOException {
    // TODO: On récupère les propriétés de la session et on y ajoute nom de l'utilisateur
    // TODO: On enregistre la session dans l'ensemble des sessions avec son identifiant comme clé
    // TODO: On crée un objet json pour signifier à tout le monde que l'utilisateur est connecté avec deux champs : 'what': 'logged' et 'who': '_username' 
    // TODO: On boucle dans l'ensemble des sessions pour signifier à tout le monde (sauf l'utilisateur) qu'un utilisateur vient de se connecter
   
    // Ajouter le nom d'utilisateur aux propriétés de la session
    _session.getUserProperties().put("username", _username);
    
    // Enregistrer la session avec l'identifiant de la session comme clé
    m_sessions.put(_session.getId(), _session);

    // Créer un objet JSON pour signaler la connexion de l'utilisateur
    JsonObject jsonMessage = new JsonObject();
    jsonMessage.put("what", "logged");
    jsonMessage.put("who", _username);
    
    // Informer tous les utilisateurs connectés de la nouvelle connexion
    for (Session session : sessions.values()) {
        if (session.isOpen()) {
            if (!session.equals(_session)) { // Ne pas envoyer à l'utilisateur qui vient de se connecter
                session.getBasicRemote().sendText(jsonMessage.toString());
            }
        }
    }
  }

  /**
   * 	Réagit à la fermeture de la connexion.
   *	@param _session La session.
    * @throws IOException 
    */
  @OnClose
  @SuppressWarnings("unchecked")
  public void onClose(Session _session, CloseReason _reason) throws IOException {
    // TODO: On récupère les propriétés de la session et on y récupère le nom l'utilisateur qui ferme la connexion
    // TODO: On supprime la session dans l'ensemble des sessions grâce à son identifiant utilisé comme clé
    // TODO: On crée un objet json pour signifier à tout le monde que l'utilisateur est déconnecté avec deux champs : 'what': 'unlogged' et 'who': 'username' 
    // TODO: On boucle dans l'ensemble des sessions pour signifier à tout le monde (sauf l'utilisateur) qu'un utilisateur vient de se déconnecter
    String username = (String) _session.getUserProperties().get("username");

    // Supprime la session de la liste
    sessions.remove(_session.getId());

    // Crée un message JSON pour informer de la déconnexion
    JsonObject jsonMessage = new JsonObject();
    jsonMessage.put("what", "unlogged");
    jsonMessage.put("who", username);

    // Notifie tous les utilisateurs restants
    broadcastMessage(jsonMessage.toString(), _session);
  }

  /**
   * 	Réagit à une erreur.
   *	@param _error L'erreur.
    */
  @OnError
  public void onError(Throwable _error) {
      System.out.println("ERROR: " + _error.getMessage());
  }

  /**
   *	Réagit à un message.
    *	@param _content Le contenu du message.
    *	@param _session La session.
    * @throws IOException 
  */
  @OnMessage(maxMessageSize = 32768)    
  @SuppressWarnings("unchecked")
  public void onMessage(String _content, Session _session) throws IOException {
    // TODO: On récupère les propriétés de la session et on y récupère le nom l'utilisateur qui a envoyé un message
    // TODO: On crée un objet json pour envoyer à tout le monde le contenu du message avec trois champs : 'what': 'message', 'who': 'username' et 'content': '_content'
    // TODO: On boucle dans l'ensemble des sessions pour envoyer à tout le monde (sauf l'utilisateur) le message
    String username = (String) _session.getUserProperties().get("username");

    JsonObject jsonMessage = new JsonObject();
    jsonMessage.put("what", "message");
    jsonMessage.put("who", username);
    jsonMessage.put("content", _content);

    // Envoie le message à tous les utilisateurs sauf l'expéditeur
    broadcastMessage(jsonMessage.toString(), _session);
  }
    
  /** L'ensemble des sessions avec l'identifiant de la session comme clé. */
  private Hashtable<String, Session> m_sessions = new Hashtable<>() ;
}