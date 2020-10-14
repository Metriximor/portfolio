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

    echo '<div class="centro">';
    echo '<p class="italico" font-size="15px">Conferência Evento X</p>';
    echo 'Your name is ' . $primNome . ' ' . $sobrNome;
    echo '</div>';
    exit;
}
?>
</body>

</html>
