import java.util.Locale ;

import javafx.application.Application ;
import javafx.scene.Scene ;
import javafx.stage.Stage ;
import javafx.scene.layout.AnchorPane;
import javafx.fxml.FXMLLoader;
import java.io.BufferedReader;
import java.net.HttpURLConnection;
import java.net.URL;

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
		_primaryStage.setTitle("JavaFX Hybrid Model-View-Controller (MVC)") ;
		FXMLLoader loader = new FXMLLoader(getClass().getResource("myscreen.fxml")) ;
		
		AnchorPane root = (AnchorPane) loader.load() ;
		MyView view = loader.getController() ;
		
		Scene scene = new Scene(root, 400, 120) ;
		_primaryStage.setScene(scene) ;
		_primaryStage.show() ;
	}
}
