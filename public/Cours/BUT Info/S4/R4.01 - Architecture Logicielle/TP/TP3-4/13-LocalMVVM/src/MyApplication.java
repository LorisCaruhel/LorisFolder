import java.util.Locale;

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
		launch(_args) ;
	}
	
	/**
	 *	Démarre.
	 * 	@param _primaryStage Le stage.
	 */
	@Override
	public void start(final Stage _primaryStage) throws Exception {
		_primaryStage.setTitle("Java Model-View-ViewModel (MVVM)") ;
		FXMLLoader loader = new FXMLLoader(getClass().getResource("myscreen.fxml")) ;
		
		AnchorPane root = (AnchorPane) loader.load() ;
		MyView view = loader.getController() ;

		// On définit l’ensemble des classes de l’architecture MVP
		// C’est là qu’il va falloir travailler !

		// On crée la vue/modèle...
		MyViewModel viewModel = new MyViewModel() ;
		// TODO: ... et les dépendances avec la vue...
		view.setViewModel(viewModel);
		
		// On crée le modèle...
		MyModel model = new MyModel() ;
		// TODO: ... et les dépendances avec la vue/modèle...
		viewModel.setModel(model);
		
		// On crée la scène à partir de la racine de l’interface graphique et on montre la fenêtre
		Scene scene = new Scene(root, 400, 120) ;
		_primaryStage.setScene(scene) ;
		_primaryStage.show() ;
	}
}
