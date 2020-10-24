
<?php
try{

	$dbh = new PDO('mysql:host=classdb.it.mtu.edu;dbname=airline', "grader", "grader");
	$dbh->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

	$statement = $dbh->prepare(" update Employee set Name=:name where Emp_no=:emp_no");

	$result = $statement->execute(array(':name' => $_POST['name'], ':emp_no' => $_POST['emp_no']));

}catch (PDOException $e) {
	print "Error! " . $e->getMessage()."<br/>";
	die();
}

?>
