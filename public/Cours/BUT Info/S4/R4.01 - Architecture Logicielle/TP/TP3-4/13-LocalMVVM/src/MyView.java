import javafx.scene.control.TextField ;
import javafx.scene.control.Label ;
import javafx.event.ActionEvent ;
import javafx.fxml.* ;

public final class MyView { 
	/** La vue/modèle. */
	private MyViewModel m_viewModel ; 
	
	// On récupère le champs de texte d'entrée du fichier myscreen.fxml
	/** L'entrée. */
	@FXML
	private TextField m_input ;
	/** La sortie. */
	@FXML
	private Label m_output ;
	
	/**
	 *	Mutateur.
	 *	@param _viewModel Le modèle de vue.
	 */
	public void setViewModel(MyViewModel _viewModel) { 
		m_viewModel = _viewModel ; 
		// TODO : On crée les liens bi-directionnels avec les propriétés de la vue/Modèle
		m_input.textProperty().bindBidirectional(m_viewModel.inputProperty());
		m_output.textProperty().bindBidirectional(m_viewModel.messageProperty());
	}
	
	@FXML
	private void handleSayHello(ActionEvent _event) {
		// TODO: On délègue l'action à la vue/modèle
		m_viewModel.sayHello();
	}
}
