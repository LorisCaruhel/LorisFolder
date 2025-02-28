import java.io.IOException;
import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.URI;
import java.net.URL;
import java.nio.charset.StandardCharsets;

/**
 *	Le main.
 */
public class MyApplication {
	/**
	 *	Lance l'application.
	 * 	@param _args Les arguments.
	 */
	public static void main(String[] _args) throws IOException {
		URL obj = new URL("http://localhost:8081/3-ServletAPI/hello?name=loris");

		HttpURLConnection con = (HttpURLConnection) obj.openConnection();
		con.setRequestProperty("name", "loris");
		con.setRequestMethod("GET");
		int responseCode = con.getResponseCode();

		if (responseCode == HttpURLConnection.HTTP_OK) { // success
			InputStream object1 = obj.openStream();

			byte[] array = new byte[100];
			object1.read(array);
			System.out.println("Donnees lu : ");

			String data = new String(array);
			System.out.println(data);

			object1.close();
		} else {
			System.out.println("Problème dans la requête code : " + responseCode);
		}
	}
}
