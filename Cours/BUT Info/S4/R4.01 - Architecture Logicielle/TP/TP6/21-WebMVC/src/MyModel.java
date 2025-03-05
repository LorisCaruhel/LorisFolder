import java.io.IOException;

import jakarta.servlet.ServletException ;
import jakarta.servlet.ServletResponse ;
import jakarta.json.Json;
import jakarta.json.JsonObject;
import java.io.PrintWriter;

/**
 *	Le modèle.
 */
public class MyModel {
	/** Le nom. */
	private String m_name ;

	/** Le service. */
	private final MyService m_service ;
	
	/**
	 *	Constructeur.
	 */
	public MyModel() {
		this(new MyService()) ;
	}
	
	/**
	 *	Constructeur.
	 *	@param _service Le service.
	 */
	public MyModel(MyService _service) {
		m_service = _service ;
	}
	
	/**
	 *	Mutateur.
	 *	@param _name Le nom.
	 *	@param _response La réponse.
	 */
	public void setName(String _name, ServletResponse _response) throws ServletException, IOException {
		m_name = _name ;
		// TODO: On notifie la vue
		this.notifyView(_response);
	}

	/**
	 *	Accesseur.
	 *	@return Le message.
	 */
	public String getMessage() {
		// TODO: On crée le message à partir du service et du nom courant
		return m_service.sayHello(m_name);
	}
	
	/**
	 *	Notifie la réponse.
	 *	@param _response La réponse.
	 */
	public void notifyView(ServletResponse _response) throws ServletException, IOException {
		// TODO: On met à jour la vue 
		JsonObject model = Json.createObjectBuilder().add("value", this.getMessage()).build();
		try(PrintWriter httpWriter = _response.getWriter()) {
			httpWriter.println(model.toString());
		}
	}
}
