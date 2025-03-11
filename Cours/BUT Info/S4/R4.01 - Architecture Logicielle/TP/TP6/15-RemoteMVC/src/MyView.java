import javafx.scene.control.TextField ;
import javafx.scene.control.Label ;

import java.io.IOException ;
import java.io.InputStream ;
import java.io.Reader ;

import java.net.HttpURLConnection ;
import java.net.URL ;
import java.net.URI ;

import jakarta.json.Json ;
import jakarta.json.JsonObject ;
import jakarta.json.JsonReader ;

import javafx.event.ActionEvent ;
import javafx.fxml.* ;

/**
 *	La vue.
 */
public class MyView {
	@FXML
	private TextField m_input ;
	@FXML
	private Label m_output ;

	/**
	 *	Réagit à l'action de l'utilisateur.
	 *	@param _event L'événement.
	 */
	@FXML
	private void handleSayHello(ActionEvent _event) throws IOException {
		// Le contrôleur est sur le serveur
	    URL controller = URI.create("http://localhost:8081/21-WebMVC/controller?name=" + getInput()).toURL() ; 

		// On délègue l'action au contrôleur sur le serveur...
		// TODO: On ouvre la connexion au modèle qui va répondre (model est de type HttpURLConnection et est récupéré à partir de l'URL de controller)
		HttpURLConnection model = (HttpURLConnection) controller.openConnection();

		// TODO: On paramètre la connexion au modèle (méthode POST, etc.)
		model.setRequestMethod("POST");

		// TODO: On se connecte
		int responseCode = model.getResponseCode();
		if (responseCode == HttpURLConnection.HTTP_OK) {
			System.out.println("Connection reussie");
			// On met à jour la vue à partir du modèle
	    	this.update(model);
		} else {
			System.out.println("Erreur dans la connection");
		}
	}

	/**
	 *	Met à jour la sortie.
	 *	@param _model Le modèle.
	 */
	public void update(HttpURLConnection _model) throws IOException {
		// TODO: On change le contenu du label de sortie à partir du message dans _model
		InputStream object1 = _model.getInputStream();

		JsonReader jsonReader = Json.createReader(object1);
        JsonObject jsonObject = jsonReader.readObject();
        jsonReader.close();

        // Récupérer les valeurs
        String monmessage = jsonObject.getString("value");

		m_output.setText(monmessage);

		object1.close();
	}

	
	/**
	 *	Accesseur.
	 *	@return Le texte d'entrée.
	 */
	public String getInput() {
		// TODO: On récupère les paramètres d'entrée à partir du nom du champ de texte 
		return m_input.getText() ;
	}

}
