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
	
		if (empty($params['id'])) {
			return $resp->withStatus(400);
		}
	
		$id = $params['id'] - 1;
	
		if (!isset($articles[$id])) {
			return $resp->withStatus(404);
		}
	
		if (!empty($params['nom'])) {
			$articles[$id]['nom'] = $params['nom'];
		}
		if (!empty($params['qte'])) {
			$articles[$id]['qte'] = (int) $params['qte'];
		}
		if (!empty($params['prix'])) {
			$articles[$id]['prix'] = (float) $params['prix'];
		}
	
		file_put_contents(__DIR__ . '/data.json', json_encode($articles, JSON_PRETTY_PRINT));
	
		return $resp->withStatus(200);
	});


	$app->patch('/articles', function ($req, $resp, $args) {
		$params = $req->getParsedBody();
		global $articles;
	
		if (empty($params['id'])) {
			return $resp->withStatus(400);
		}
	
		$id = $params['id'] - 1;
	
		if (!isset($articles[$id])) {
			return $resp->withStatus(404);
		}
	
		if (!empty($params['nom'])) {
			$articles[$id]['nom'] = $params['nom'];
		}
		if (!empty($params['qte'])) {
			$articles[$id]['qte'] = (int) $params['qte'];
		}
		if (!empty($params['prix'])) {
			$articles[$id]['prix'] = (float) $params['prix'];
		}
	
		file_put_contents(__DIR__ . '/data.json', json_encode($articles, JSON_PRETTY_PRINT));
	
		return $resp->withStatus(200);
	});
	
	$app->delete('/articles/{id}', function ($req, $resp, $args) {
		global $articles;
		$id = $args['id'] - 1;
	
		if (!isset($articles[$id])) {
			return $resp->withStatus(404);
		}
	
		unset($articles[$id]);
	
		file_put_contents(__DIR__ . '/data.json', json_encode($articles, JSON_PRETTY_PRINT));
	
		return $resp->withStatus(200);
	});

	// Fix "bug" (?) avec PUT vide (body non parsé)
	$app->addBodyParsingMiddleware();
	$app->run();

?>
