import javafx.application.Application ;
import javafx.scene.Scene ;
import javafx.stage.Stage ;
import javafx.scene.layout.AnchorPane;
import javafx.fxml.FXMLLoader;

/**
 *	Le main.
 */
public final class MyApplication extends Application {
	/**
	 *	Lance l'application.
	 * 	@param _args Les arguments.
	 */
	public static void main(String[] _args) {
		launch(_args);
	}
	
	/**
	 * @see Application#start(final Stage _primaryStage)
	 */
	@Override
	public void start(final Stage _primaryStage) throws Exception {
		// Création du loader.
		final FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("myscreen.fxml"));
		// Chargement du FXML.
		final AnchorPane root = (AnchorPane) fxmlLoader.load();
		// Création de la scène.
		final Scene scene = new Scene(root, 300, 250);
		
		_primaryStage.setScene(scene);
		_primaryStage.setTitle("Test FXML");
		_primaryStage.show();
	}
}
