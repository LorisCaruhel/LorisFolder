<?php
	// NB : C'est du quick and dirty. Pas de test si pb accès item inexistant
	// $articles = [
	// 	1 => array('nom' => 'Livre'),
	// 	2 => array('nom' => 'Crayon'),
	// ];
	$articles = json_decode(file_get_contents(__DIR__ . '/data.json'),true);

	function save($nom, $qte, $prix) {
		$fichier = __DIR__ . '/data.json';
		global $articles;
	
		$newArticle = [
			"id" => count($articles) + 1,
			"nom" => $nom,
			"quantite" => $qte,
			"prix" => $prix
		];
		
		$articles[] = $newArticle;
	
		file_put_contents($fichier, json_encode($articles, JSON_PRETTY_PRINT));
	}

	function put($articles) {
		$fichier = __DIR__ . '/data.json';
		file_put_contents($fichier, json_encode($articles, JSON_PRETTY_PRINT));
	}
	

	$app->get('/', function($req, $resp) {
		return buildResponse($resp, 'Ca maaaaarche !');
	});

	$app->get('/articles', function($req, $resp) {
		global $articles;

		$ret = array();
		foreach ($articles as $key => $val) {
			$item = $val;
			$item['id'] = $key;
			$ret[] = $item;
		}
		return buildResponse($resp, $ret);
	});

	$app->get('/articles/{id}', function($req, $resp, $args) {
		global $articles;

		$id = $args['id'];
		$item = $articles[$id];
		$ret = $item;

		return buildResponse($resp, $ret);
	});

	$app->post('/articles', function ($req, $resp, $args) {
		$params = $req->getParsedBody();
		save($params['nom'], $params['qte'], $params['prix']);
		return $resp->withStatus(201);
	});

	$app->put('/articles', function ($req, $resp, $args) {
		$params = $req->getParsedBody();
		global $articles;
	
		$nbArticles = count($articles) - 1;
		$idTrouver = null;
	
		// Rechercher l'article
		while ($nbArticles >= 0) {
			if ($articles[$nbArticles]['id'] == $params['id']) {
				$idTrouver = $nbArticles;
				break;
			}
			$nbArticles--;
		}
	
		// Changer les champs qu'il faut
		if ($idTrouver !== null) {
			if (!empty($params['nom'])) {
				$articles[$idTrouver]['nom'] = $params['nom'];
			}
			if (!empty($params['qte'])) {
				$articles[$idTrouver]['qte'] = $params['qte'];
			}
			if (!empty($params['prix'])) {
				$articles[$idTrouver]['prix'] = $params['prix'];
			}
	
			put($articles);
			// Tout ce passe bien 
			return $resp->withStatus(200);
		}
	
		// Pas d'article trouvé
		return $resp->withStatus(404)->write('Article non trouvé');
	});
	

	// Fix "bug" (?) avec PUT vide (body non parsé)
	$app->addBodyParsingMiddleware();
	$app->run();

?>
