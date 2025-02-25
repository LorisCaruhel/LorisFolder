<?php
	// NB : C'est du quick and dirty. Pas de test si pb accès item inexistant
	// $articles = [
	// 	1 => array('nom' => 'Livre'),
	// 	2 => array('nom' => 'Crayon'),
	// ];
	$fic = __DIR__ . '/data.json';
	if (file_exists($fic)) {
		$articles = json_decode(file_get_contents($fic), true);
	} else {
		$articles = '{
	"1": {
		"nom": "Livre",
		"prix": 1,
		"qte": 20
	},
	"2": {
		"nom": "Livre",
		"prix": 1,
		"qte": 20
	}
}';
		file_put_contents($fic, $articles);
	}

	// Fonction qui sauvegarde les éléments dans articles une fois modifier selon la route API
	function save($articles) {
		$fichier = __DIR__ . '/data.json';
		global $articles;
	
		file_put_contents($fichier, json_encode($articles, JSON_PRETTY_PRINT));
	}
	

	$app->get('/', function($req, $resp) {
		return buildResponse($resp, 'Ca maaaaarche !');
	});

	$app->get('/articles', function($req, $resp) {
		global $articles;

		// Créer le tableau avec tous les articles
		$ret = array();
		foreach ($articles as $key => $val) {
			$item = $val;
			$item['id'] = $key;
			$ret[] = $item;
		}

		// Le mettre dans le body de la requête de réponse 
		return buildResponse($resp, $ret);
	});

	$app->get('/articles/{id}', function($req, $resp, $args) {
		global $articles;

		$id = $args['id'];

		// Vérifier que l'article existe bien
		if(!isset($articles[$id])) {
			return $resp->withStatus(404);
		}

		// Le sélectionner
		$item = $articles[$id];
		$ret = $item;

		// Puis le mettre dans le body de la requête de réponse
		return buildResponse($resp, $ret);
	});

	$app->post('/articles', function ($req, $resp, $args) {
		$params = $req->getParsedBody();
		global $articles;

		// Créer un nouvelle article à partir du body de la requête
		$newArticle = [
			"nom" => $params['nom'],
			"quantite" => $params['qte'],
			"prix" => $params['prix']
		];
		
		// Le rajouter dans le tableau des articles
		$articles[] = $newArticle;

		// Le sauvegarder dans notre fichier data.json
		save($articles);
		return $resp->withStatus(201);
	});

	$app->put('/articles/{id}', function ($req, $resp, $args) {
		$params = $req->getParsedBody();
		global $articles;
	
		// Le put modifie tout l'objet pas seulement une partie.
		if (empty($params['nom']) || empty($params['qte']) || empty($params['prix'])) {
			return $resp->withStatus(400);
		}
	
		$id = $args['id'];
	
		// Vérifier s'il existe
		if (!isset($articles[$id])) {
			return $resp->withStatus(404);
		}
		
		// Le modifier
		$articles[$id]['nom'] = $params['nom'];
		$articles[$id]['qte'] = (int) $params['qte'];
		$articles[$id]['prix'] = (float) $params['prix'];
	
		// Le sauvegarder dans notre fichier data.json
		save($articles);
	
		return $resp->withStatus(200);
	});


	$app->patch('/articles/{id}', function ($req, $resp, $args) {
		$params = $req->getParsedBody();
		global $articles;
		$id = $args['id'];
	
		// Vérifier s'il existe
		if (!isset($articles[$id])) {
			return $resp->withStatus(404);
		}
	
		// Modifier seulement les parties que la requête modifie car c'est un patch
		if (!empty($params['nom'])) {
			$articles[$id]['nom'] = $params['nom'];
		}
		if (!empty($params['qte'])) {
			$articles[$id]['qte'] = (int) $params['qte'];
		}
		if (!empty($params['prix'])) {
			$articles[$id]['prix'] = (float) $params['prix'];
		}
	
		// Le sauvegarder dans notre fichier data.json
		save($articles);
	
		return $resp->withStatus(200);
	});
	
	$app->delete('/articles/{id}', function ($req, $resp, $args) {
		global $articles;
		$id = $args['id'];
	
		// Vérifie s'il existe
		if (!isset($articles[$id])) {
			return $resp->withStatus(404);
		}
	
		// Supprimer l'article du tableau
		unset($articles[$id]);
	
		// Le sauvegarder dans notre fichier data.json
		save($articles);
	
		return $resp->withStatus(200);
	});

	// Fix "bug" (?) avec PUT vide (body non parsé)
	$app->addBodyParsingMiddleware();
	$app->run();

?>
