<html>

<head>
    <meta chartset="UTF-8" http-equiv="Content-Type" content="text/html;charset=ISO-8859-1" />
    <title>Sou memo fixe épóas</title>
</head>

<body>
    <?php
$res;
$var0 = "DEAPC ";
$var1 = 2017;
$var2 = "/";
$var3 = 2018;
$res= $var0 . $var1 . $var2 . $var3;
echo $res;
    ?>
        <form action="index.php" method="GET">
            <p>
                Título profissional: <input type="text" name="tit" />
                <br> Primeiro nome: <input type="text" name="pnome" />
                <br> Ultimo nome: <input type="text" name="unome" />
                <br> Idade: <input type="number" name="idd" min="1" max="100" />
                <br> Submit Query: <input type="submit" />
            </p>
            <p>
                <b> Viva </b>
                <u> <i> <?php echo ($_GET["tit"]); ?> </i> </u>
                <u> <i> <?php echo ($_GET["pnome"]); ?> </i> </u>
                <u> <i> <?php echo ($_GET["unome"]); ?> </i> </u>
                <b> parab&eacute;ns pelos </b>
                <u> <i> <?php echo ($_GET["idd"]); ?> </i> </u>
                <b> anos. </b>
            </p>
        </form>

        <p> O meu primeiro script em php. VÉLÀRDÈ</p>

</body>

</html>
