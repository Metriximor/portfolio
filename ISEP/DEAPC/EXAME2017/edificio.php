<!DOCTYPE html>
<html>

<head>
    <title> Teste DEAPC </title>
    <meta charset="UTF-8">
</head>

<body>
    <?php
    if ( isset( $_POST['submit'] ) ) {  
      
    $comp = $_POST['comp'];
    $larg = $_POST['larg'];
    $numAnd = $_POST['numAnd'];
    $altAnd = $_POST['altAnd'];
    $numJanPor = $_POST['numJanPor'];
    $arJanPor = $_POST['arJanPor'];
    $rend = $_POST['rend'];
        
    //Altura total do prédio vai ser altura dos andares vezes tamanho dos andares
    $alturaPredio = $altAnd * $numAnd;
    //as exceções vao ser o num de janelas vezes a sua area em m2
    $excepcoes = $numJanPor * $arJanPor;
    //Qtd total de tinta vai ser alt*comprimento*2 + alt*largura*2 menos as exceçoes
    $resultado = ($alturaPredio * $comp * 2) + ($alturaPredio * $larg * 2) - $excepcoes;
        
    //O numero de litros de tinta necessarios depende da área / o rendimento
    $resultadoTinta = $resultado / $rend;
    
    
    //Imprime a página
    echo '<h1>Tinta Necessária</h1>';
    echo '<b>Área total pintura:</b> ' . $resultado . ' metros quadrados' . '<br>';
    echo '<b>Litros de tinta necessários:</b> ' . $resultadoTinta . ' litro(s)';
    exit;
    }
    ?>
</body>

</html>
