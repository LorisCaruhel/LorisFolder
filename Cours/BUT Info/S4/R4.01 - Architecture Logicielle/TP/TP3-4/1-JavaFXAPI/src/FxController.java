import javafx.scene.control.*;

import javafx.event.ActionEvent ;
import javafx.fxml.* ;

/**
 *	La vue.
 */
public class FxController {
	@FXML
	private Label m_message;
	private Button bouton;

	/**
	 *	Réagit à l'action de l'utilisateur.
	 *	@param _event L'événement.
	 */
	@FXML
	private void sayHelloWorld(ActionEvent _event) {
		if(!m_message.getText().trim().isEmpty()) {
			m_message.setText("");
		}else {
			m_message.setText("Hello World !");
		}
	}
}