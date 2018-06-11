<!DOCTYPE html>
<html>

<head>
    <meta charset="UTF-8">
    <title>Ficha Javascript</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="stylesheet.css">
</head>

<body>
    <?php 
    $nome = $_POST['nome'];
    $idade = $_POST['aniversario'];
    $contador = 0;
    
    $ficheiro = fopen("socios.dat", "w") or die("Erro ao abrir ficheiro!");
    
    while($nome[$contador]!=null)
    {
        $contador++;
    }
    
    //$texto = '1' . ':' . $nome . ':' . $idade . "\n";
    //fwrite($ficheiro, $texto);
    fclose($ficheiro);    
    //Debug: echo($nome . ' ' . $idade); 
    ?>
</body>

</html>
