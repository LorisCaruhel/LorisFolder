import java.io.StringReader;
import java.io.StringWriter;

import jakarta.json.Json;
import jakarta.json.JsonReader;
import jakarta.json.JsonWriter;
import jakarta.json.JsonObject;
import jakarta.json.JsonArray;
import jakarta.json.JsonWriter;

public class MyApplication {
	/**
	 *	Lance l'application.
	 * 	@param _args Les arguments.
	 */
	public static void main(String[] _args) {
        String jsonString = create() ;
        System.out.println(jsonString) ;
        parse(jsonString);
	}

	/**
	 *	Créée le Json.
	 * 	@return La chaîne du Json.
	 */
    private static String create() {
		JsonObject model = Json.createObjectBuilder().add("monmessage", "Hello world !")
													 .add("montableau", Json.createArrayBuilder()
																			 .add("valeur1")
																			 .add("valeur2")
																			 .add("valeur3")).build();

		return model.toString();
    }

	/**
	 *	Parcours le Json.
	 * 	@param _jsonString La chaîne du Json.
	 */
    private static void parse(String _jsonString) {
		JsonReader jsonReader = Json.createReader(new StringReader(_jsonString));
        JsonObject jsonObject = jsonReader.readObject();
        jsonReader.close();

        // Récupérer les valeurs
        String monmessage = jsonObject.getString("monmessage");
        JsonArray montableau = jsonObject.getJsonArray("montableau");

		System.out.println("Mon message : " + monmessage);
        // Afficher les valeurs
		for(int i = 0; i<3; i++) {
        	System.out.println("Valeur du tableau : " + montableau.getString(i));
		}
    }
}
