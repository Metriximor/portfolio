<!DOCTYPE html>
<html>

<head>
    <meta charset="UTF-8">
    <title>Inscrição</title>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="stylesheet.css">
</head>

<body>
    <?php
if ( isset( $_GET['submit'] ) ) {  
    $primNome = $_GET['primNome']; 
    $sobrNome = $_GET['sobrNome'];
    $titulo = $_GET['titulo'];
    $instituto = $_GET['instit'];
    $email = $_GET['email'];
    $sexo = $_GET['sexo'];

    echo '<div class="centro">';
    
    echo '<p class="bold italic" id="primeiraLinha">Conferência Evento X</p>';
    
    echo '<p id="segundaLinha">';
    echo '<span class="italico">' . $titulo;
    //Designa a versão correta feminina do titulo
    if($sexo == 'female' && $titulo != 'Prof' && $titulo != 'Eng') {
        echo 'a.';
    }
    else if($sexo == 'female' && ($titulo == 'Prof' || $titulo == 'Eng')) {
        echo '.ª';
    }
    else {
        echo '.';
    }
    echo '</span>' . ' ';
    echo '<span class="italico bold">' . $sobrNome . '</span>';
    echo ', ' . $primNome;
    echo '</p>';
    
    echo '<p id="terceiraLinha">';
    echo '<span class="bold">' . $instituto . '</span>';
    echo '</p>';
    
    echo '<p id="quartaLinha" class="bold">';
    echo 'E-mail :' . '<span class="italico">' . $email . '</span>';
    echo '</p>';
    
    echo '</div>';
    exit;
}
?>
<form action="index.html">
    <input type="button" value="Concluir">
</form>
</body>

</html>
