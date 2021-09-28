<html>
<body style="background-color:HotPink;">
<h1 style="color:White;text-align:center;">Guess the Number</h1>
<?php
	$user_input=$_POST["userinput"];
	$rand_array=array(0,0,0,0,0);
	$array_length = count($rand_array);
	$answer = False;
	for($i=0; $i<$array_length; $i++) {
		$rand_array[$i] = rand(0,20);
		echo $rand_array[$i]. " ";
	}
	for($j=0; $j<$array_length; $j++){
		if($user_input == $rand_array[$j]) {
                       $answer = True;     
			break;
		} else {
                        $answer = False;
		}
	}

	if($answer == True) {
		echo "<p> You guessed the correct number.</p>";
	}
	else if($answer == False) {
		echo "<p> That is incorrect. Please try again. </p>";
	}		
?>

<form method="POST"action="lab3.html">
   <input type="submit"value="Try again"/>
</form>
		
</body>
</html>
