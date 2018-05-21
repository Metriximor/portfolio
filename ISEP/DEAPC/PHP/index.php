<html>
<head>
<meta http-equiv="Content-Type" content="text/html;charset=ISO-8859-1"/>
<title>Título da página</title>
</head>
<body>
<?php
$res;
$var0 = "DEAPC ";
$var1 = 2016;
$var2 = "/";
$var3 = 2017;

$res= $var0 . $var1 . $var2 . $var3;
echo $res;

<form action="index.php" method="GET">
Título profissional: <input type="text" name="tit" />
Primeiro nome: <input type="text" name="pnome" />
Ultimo nome: <input type="text" name="unome" />
Idade: <input type="number" age="idd" />
Submit Query: <input type="submit" />

<b> Viva </b> 
<u> <i> <?php echo $_GET["tit"]); ?> </i> </u>  
<u> <i> <?php echo $_GET["pnome"]); ?> </i> </u> 
<u> <i> <?php echo $_GET["unome"]); ?> </i> </u> 
<b> parab&eacute;ns pelos </b> 
<u> <i> <?php echo $_GET['idd']); ?>; </i> </u> 
<b> anos. </b>
</form>

?>

<p> O meu primeiro script em php. </p>

</body>
</html>
