/**
 *	Accesseur.
 *	@return Le texte d'entrée.
 */
function getInput() {
	let input = document.getElementById('m_input') ;
	return input.value ;	
}

/**
 *	Réagit à la mise à jour.
 *	@param _event L'événement.
 */
function update(_event) {
	const xhr = _event.currentTarget ;
	
	if ((xhr.readyState == 4) && (xhr.status == 200)) {
		const resultSet = JSON.parse(xhr.responseText) ;
		if (resultSet != null) {
			// TODO: On change le contenu du label de sortie à partir du message du modèle
			let elem = document.getElementById('m_output').innerHTML = resultSet.value;
		}
	}
}

/**
 *	Réagit à l'action du bouton.
 */
function handleSayHello() {
	const xhr = new XMLHttpRequest() ;

	// TODO: On délègue l'action à l'URL du contrôleur
	xhr.open("GET", "controller?name="+getInput(), true);
	xhr.onreadystatechange = (e) => {
		update(e);
	}
    xhr.send();

	return xhr;
}

