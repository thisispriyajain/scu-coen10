<html>
<body style="background-color:Lavender;">
<h1 style="color:HotPink;text-align:center;">Multiplication Game </h1>

<?php
	$numone=$_POST["numone"];
	$numtwo=$_POST["numtwo"];
	$userinput=$_POST["userinput"];
	
	if($userinput == $numone * $numtwo)
		echo "That is correct!";
	else
		echo "That is incorrect. The correct answer is ". $numone  * $numtwo;
?>

<form method="POST"action="lab2a.php">
   <input type="submit"value="Try again"/>
</form>

</body>
</html>
