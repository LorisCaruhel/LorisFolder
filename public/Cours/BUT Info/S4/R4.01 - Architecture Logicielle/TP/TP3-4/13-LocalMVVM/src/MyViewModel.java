import javafx.beans.property.StringProperty;
import javafx.beans.property.SimpleStringProperty;

/**
 *	Le présentateur.
 */
public final class MyViewModel {
	/** La propriété de l'entrée. */
	private StringProperty m_input ;

	/** La propriété du message. */
	private StringProperty m_message ;

	/** Le modèle. */
	private MyModel m_model ;

	/** Le service. */
	private final MyService m_service ;
	
	/**
	 *	Constructeur.
	 */
	public MyViewModel() {
		this(new MyService()) ;
	}
	
	/**
	 *	Constructeur.
	 *	@param _service Le service.
	 */
	public MyViewModel(MyService _service) {
		m_service = _service ;
	}
	
	/**
	 *	Mutateur.
	 *	@param _model Le modèle.
	 */
	public void setModel(MyModel _model) {
		m_model = _model ;
	}
	
	/*
	 *	Accesseur.
	 *	@return La propriété d'entrée. 
	 */
	public StringProperty inputProperty() {
		// TODO : On instancie la propriété d'entrée si elle n'est pas instanciée, puis on la retourne
		if(m_input == null) {
			m_input = new SimpleStringProperty("");
		}
		return m_input;
	}
	
	/**
	 *	Accesseur.
	 *	@return L'entrée.
	 */
	private String getInput() {
		// TODO : On renvoie le texte de la propriété ou null si elle n'est pas instanciée
		if(m_input == null) {
			return null;
		}
		return m_input.getValue();
	}
	
	/*
	 *	Accesseur.
	 *	@return La propriété du message. 
	 */
	public StringProperty messageProperty() {
		// TODO : On instancie la propriété de message si elle n'est pas instanciée, puis on la retourne
		if(m_message == null) {
			m_message = new SimpleStringProperty("");
		}
		return m_message;
	}
	
	/**
	 *	Accesseur.
	 *	@return Le message.
	 */
	private void setMessage(String _message) {
		// TODO : On modifie le texte de la propriété message
		this.messageProperty().setValue(_message);
	}
	
	/**
	 *	Dit bonjour.
	 */
	public void sayHello() {
		// TODO : On récupère le texte d'entrée
		String nom = this.getInput();
		// TODO : On modifie le nom du modèle
		m_model.setName(nom);
		// TODO : On modifie le message
		this.setMessage(m_service.sayHello(nom));
	}
	
}