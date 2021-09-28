<html>
<body style="background-color:Lavender;">
<h1 style="color:HotPink;text-align:center;">Multiplication Game</h1>
<?php
	 $numone=rand(0,12); 
	 $numtwo=rand(0,12);
	 $userinput=0;
	echo $numone. "x". $numtwo. "=";
?>

<form action="lab2b.php" method="POST">
<input type="hidden"name="numone"value="<?php echo $numone; ?>" />
<input type="hidden"name="numtwo"value="<?php echo $numtwo; ?>" />
<input type="number"name="userinput"/>
<input type="submit"value="Calculate!"/>
</form>
</body>
</html>
