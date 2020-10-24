<head>
</head>

<?php

try{
	$dbh = new PDO ('mysql:host=classdb.it.mtu.edu;dbname=airline', "cs3425gr", "cs3425gr");
	$dbh->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

	echo "<table border='1'>";
	echo "<TR>";
	echo "<TH> name </TH>";
	echo "<TH> Emp_no </TH>";
	echo "</TR>";

	foreach ( $dbh->query( "SELECT Name, Emp_no name FROM Employee") as $row){
		echo "<TR>";
		echo "<TD>".$row[0]."</TD>";
		echo "<TD>".$row[1]."</TD>";
		echo '<form method="post" action="edit_employee.php">';
		echo '<TD> <input type="submit" name="edit" value="Edit"> </TD>';
                echo '<TD> <input type="hidden" name = "name" value=" '.$row[0].' "></TD>';
                echo '<TD> <input type="hidden" name = "emp_no" value= "'.$row[1].' "></TD>';
		echo '</form>';
		echo "</TR>";
	}

	echo "</table>";

}catch (PDOException $e){
	print "Error! " . $e->getMessage()."<br/>";
	die();
}

?>
