<?php

if (isset($GLOBALS["HTTP_RAW_POST_DATA"])){
	$xml = xmldoc($GLOBALS["HTTP_RAW_POST_DATA"]);
	
	$file = fopen("data.txt","wb");
	fwrite($file, $xml);
	fclose($file);
	
	echo("<status>File saved.</status>");
}

?>