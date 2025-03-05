/**
 *	Réagit à la réception du contenu dynamique.
 *	@param _event L'événement.
 */
 function sayHello(_event) {
    // let div = document.getElementById("m_message").innerHTML = _event;
    console.log(_event);
}

/**
 *	Réagit à l'action du bouton.
 */
function handleSayHello() {
    // http://localhost:8081/0-WebTest/test
    const req = new XMLHttpRequest();
    req.open("GET", "http://localhost:8081/0-WebTest/test?name=loris", true);
    req.onreadystatechange = () => {
        sayHello(req.response)
    }
    req.send();
}
