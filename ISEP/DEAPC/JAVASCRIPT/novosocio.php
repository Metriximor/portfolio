<!DOCTYPE html>
<html>

<head>
    <meta charset="UTF-8">
    <title>Ficha Javascript</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="stylesheet.css">
</head>

<body class="ultimoex">
    <?php 
    $nome = array_filter($_POST['nome']);
    $idade = array_filter($_POST['aniversario']);
    $ordena = $_POST['ordena'];
    
    if($ordena=="nome") {
        array_multisort($nome, SORT_NATURAL | SORT_FLAG_CASE, $idade);
    }
    else if($ordena=="data") {
        array_multisort($idade, $nome, SORT_NATURAL | SORT_FLAG_CASE);
    }
    
    $ficheiro = fopen("socios.dat", "w") or die("Erro ao abrir ficheiro!");
    
    for($i = 0; $i < count($nome); $i++) {
        $texto = $i+1 . ':' . $nome[$i] . ':' . $idade[$i] . "\n";
        fwrite($ficheiro, $texto);
        
        echo $i+1 . ':' . $nome[$i] . ':' . $idade[$i] . "<br>";
    }
    fclose($ficheiro);    
    //Debug: echo($nome . ' ' . $idade); 
    ?>
</body>

</html>
