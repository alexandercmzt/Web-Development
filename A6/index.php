<?php
use \Psr\Http\Message\ServerRequestInterface as Request;
use \Psr\Http\Message\ResponseInterface as Response;

require 'vendor/autoload.php';

$app = new \Slim\Slim();

$app->post('/', function (Request $request) {
	$data = $request->getParsedBody();
    shell_exec("python ./cgi-bin/server.cgi").escapeshellarg($data);
});
$app->run();