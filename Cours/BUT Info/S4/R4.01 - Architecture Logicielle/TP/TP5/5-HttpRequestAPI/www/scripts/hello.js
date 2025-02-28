/**
 *	Réagit à la réception du contenu dynamique.
 *	@param _event L'événement.
 */
 function sayHello(_event) {
}

/**
 *	Réagit à l'action du bouton.
 */
function handleSayHello() {
    // http://localhost:8081/0-WebTest/test
    const req = new XMLHttpRequest();
    req.addEventListener("load", reqListener);
    req.open("GET", "http://localhost:8081/0-WebTest/test");
    req.send();
}
