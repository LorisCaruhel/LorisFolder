/** La websocket. */
var socket = null ;

/** Le nom de l'utilisateur. */
var username = null ;

/**
 *	Réagit à une connexion.
 *	@param _event L'événement.  
 */
function whenLogged(_event) {
	if (socket != null) {
		// TODO: On notifie l'utilisateur qu'il est connecté
		let connectText = document.createElement("p");
		connectText.innerHTML += "Vous êtes connecté(e) en tant que " + username;
		connectText.classList.add("logged");

		document.querySelector("#chat").appendChild(connectText);

		// TODO: On cache le champ de texte et le bouton [Se connecter]
		document.querySelector("#loginscreen").style.cssText = "visibility: hidden;";
		// TODO: On affiche le champ de texte et les boutons [Envoyer] et [Se déconnecter]
		document.querySelector("#chatscreen").style.cssText = "visibility: visible;";
	}
}

/**
 *	Réagit à une déconnexion.
 *	@param _event L'événement.  
 */
function whenUnlogged(_event) {
	if (socket != null) {
		// TODO: On notifie l'utilisateur qu'il est déconnecté
		let disconnectText = document.createElement("p");
		disconnectText.innerHTML += "Vous êtes déconnecté(e)";
		disconnectText.classList.add("unlogged");

		document.querySelector("#chat").appendChild(disconnectText);

		// TODO: On affiche le champ de texte et le bouton [Se connecter]
		document.querySelector("#loginscreen").style.cssText = "visibility: visible;";
		// TODO: On cache le champ de texte et les boutons [Envoyer] et [Se déconnecter]
		document.querySelector("#chatscreen").style.cssText = "visibility: hidden;";
	}	
}

/**
 *	Réagit à la réception d'un message.
 *	@param _event L'événement.  
 */
 function whenReceived(_event) {
    if (socket != null) {
        let chat = document.querySelector("#chat");

        let data;
        try {
            data = JSON.parse(_event.data);
        } catch (error) {
            console.error("Erreur de parsing JSON : ", error);
            return;
        }

        switch(data.what) {
            case "logged":
                let connectText = document.createElement("p");
                connectText.innerHTML = data.who + " est maintenant connecté(e)";
                chat.appendChild(connectText);
                break;
            case "unlogged":
                let disconnectText = document.createElement("p");
                disconnectText.innerHTML = data.who + " est maintenant déconnecté(e)";
                chat.appendChild(disconnectText);
                break;
            case "message":
                let receivedMessage = document.createElement("p");
                receivedMessage.innerHTML = data.who + " : " + data.content;
                receivedMessage.classList.add("sent");
                chat.appendChild(receivedMessage);
                break;
            default:
                console.log("Aucun cas pour ", data.what);
                break;
        }
    }
}

/**
 *	Connecte.
 */
function onLogin() {
	// TODO: On instantie socket et username. 
	// TODO: La variable socket est reliée aux bons événements via socket.addEventListener(...) 
	// La socket pointera vers ‘ws://localhost:8080/31-WebChat/WebSocket/{username}’ où {username} est la valeur de la variable username.
	username = document.querySelector("#name").value;
	socket = new WebSocket(`ws://localhost:8081/32-WebChat/WebSocket/${username}`);
	socket.onopen = whenLogged;
	socket.onclose = whenUnlogged;
	socket.onmessage = whenReceived;
}

/**
 *	Déconnecte.
 */
function onLogout() {
	if (socket != null) {
		// TODO: On ferme la connextion
		socket.close();
	}
}

/**
 *	Envoie.
 */
function onSend() {
	if (socket != null) {
		// TODO: On envoie le message
		// On suppose que le message ne contient que le texte
		let message = document.querySelector("#message").value;
		if(message) {
			socket.send(message);
			let sentMessage = document.createElement("p");
			sentMessage.innerHTML = "Vous : " + message;
			sentMessage.classList.add("received");
			chat.appendChild(sentMessage);
		}
	}
}
