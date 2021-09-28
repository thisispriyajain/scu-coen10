<!--Priya Jain-->
<!--COEN 10L-->
<!--Tuesday,9:15am-->

<html>
<body style="background-color:White;">
<h1 style="color:DeepPink;text-align:center;">Lottery Game</h1>
<?php
	$un_one=$_POST["usernum1"];
	$un_two=$_POST["usernum2"];
	$un_three=$_POST["usernum3"];
	$un_four=$_POST["usernum4"];
	$un_five=$_POST["usernum5"];
	
	
	$user_array=array($un_one, $un_two, $un_three, $un_four, $un_five);
	$lotto_array=array(0,0,0,0,0);
	
	$user_size=count($user_array);
        $lotto_size=count($lotto_array);
        $counter = 0;
	
	//This loop generates random numbers from 1 to 20 and prints the array. 
	for($i=0; $i<$lotto_size; $i++) {
		$lotto_array[$i] = rand(1,20);
		echo $lotto_array[$i]. " ";
	}

	//This loop checks if there are any duplicates in the lottery array. 
	for($i=0;$i<5;$i++) {
		for($j=$i-1; $j>=0;$j--) {
			if($lotto_array[$i]==$lotto_array[$j]) {
				$i--;
				break;
			}
		}
	}

	//This loop checks for the number of matches between the lottery and user array.
	for($i=0;$i<$user_size;$i++) {
		for($j=0;$j<$lotto_size;$j++) {
			if($user_array[$i]==$lotto_array[$j]) {
				$counter++;
			}
		}
	}
	echo "<p> There are " .$counter. " matches.</p>";
 	 	
?>

<form method="POST"action="lab4.html">
   <input type="submit"value="Try again"/>
</form>		

</body>
</html>
