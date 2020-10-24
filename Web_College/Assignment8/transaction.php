<head>
~ Bank of Kriz ~<br/><br/>
</head>


<?php
#var_dump($_POST);  onclick=setURL()
$debug = 0;
if (isset($_POST['ok'])){
	$SAN = $_POST["SANum"];
	$CAN = $_POST["CANum"];
	$AMT = $_POST["Amount"]; # A Double
	
	// Destroy injection chars
	$SAN = str_replace("'","",$SAN);
	$SAN = str_replace("--","",$SAN);
	$CAN = str_replace("'","",$CAN);
	$CAN = str_replace("--","",$CAN);

	$expr_SAcc = "SELECT balance as balance FROM saving WHERE account_number = ?";
	$expr_CAcc = "SELECT balance as balance FROM checking WHERE account_number = ?";
	$expr_transS = "UPDATE saving SET balance = balance - ? WHERE account_number = ?";
	$expr_transC = "UPDATE checking SET balance = balance + ? WHERE account_number = ?";

	$servername = "classdb.it.mtu.edu";
	$username = "bakriz";
	$password = "password";
	$conn = null; // Make it known in this scope
	// Create connection
	try {
		$conn = new PDO("mysql:host=$servername;dbname=bakriz", $username, $password);
		$conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		echo "<br/>Connection Established...<br/>";
	} catch (PDOException $e) {
		echo "<br/>Connection failed: " . $e->getMessage();
	}

	# === Select, print, check, print, select, print, done ====
	try{
		// DEBUG SECTION
		if ($debug){
		$stmt = $conn->query("SELECT balance as balance, account_number as id FROM saving" ); //WHERE account_number = $SAN"
		$stmt2 = $conn->query("SELECT balance as balance, account_number as id FROM checking"); //WHERE account_number = $CAN"
		}
		// END DEBUG
		
		$res = null;
		
		// Generate Before
		$conn->beginTransaction();
		$SAcc_pre = $conn->prepare($expr_SAcc);
		$SAcc_pre->execute(array($SAN));
		$S_count = $SAcc_pre->rowCount();
		$conn->commit();
		
		$SPRR = $SAcc_pre->fetch(PDO::FETCH_ASSOC);
		$x = $SPRR['balance'];
		
		$conn->beginTransaction();
		$CAcc_pre = $conn->prepare($expr_CAcc);
		$CAcc_pre->execute(array($CAN));
		$C_count = $CAcc_pre->rowCount();
		$conn->commit();
		
		$CPRR = $CAcc_pre->fetch(PDO::FETCH_ASSOC);
		
		
		if ($S_count != 1){
			echo "<br/><font color='red'>ERROR!<br/> Make sure the Savings account is valid!</font> <br/>(Your input has NOT been destroyed)<br/><br/>";
			echo "<a href=\"javascript:history.go(-1)\">GO BACK & EDIT</a>";		
			exit();
		}
		if ($C_count != 1){
			echo "<br/><font color='red'>ERROR!<br/> Make sure the Checking account is valid!</font> <br/>(Your input has NOT been destroyed)<br/><br/>";
			echo "<a href=\"javascript:history.go(-1)\">GO BACK & EDIT</a>";
			exit();
		}
		if ($x-$AMT < 0){
			// No good...
			echo "<font color='red'>Insufficient Funds!<br/> Account $SAN only has $$x (Less than $$AMT amount)</font> <br/>(Your input has NOT been destroyed)<br/><br/>";
			echo "<a href=\"javascript:history.go(-1)\">GO BACK & EDIT</a>";
			exit();
		}else{
			// Do it!
			$conn->beginTransaction();
			
			$res1 = $conn->prepare($expr_transS);
			$res1->execute(array($AMT,$SAN));
			
			$res2 = $conn->prepare($expr_transC);
			$res2->execute(array($AMT,$CAN));
			
			$conn->commit();
		}
		
		// Generate After
		$conn->beginTransaction();
		$SAcc_post = $conn->prepare($expr_SAcc);
		$SAcc_post->execute(array($SAN));
		$conn->commit();
		$SPOR= $SAcc_post->fetch(PDO::FETCH_ASSOC);
		
		$conn->beginTransaction();
		$CAcc_post = $conn->prepare($expr_CAcc);
		$CAcc_post ->execute(array($CAN));
		$conn->commit();
		$CPOR= $CAcc_post->fetch(PDO::FETCH_ASSOC);

		// Do a full print out
		echo "<font color='green'>Transfer succeeded!</font><br/><br/>";
		echo "From saving account $SAN <br/>";
		echo "• Previous balance: $".(float)$SPRR['balance']."<br/>";
		echo "• New balance: $".(float)$SPOR['balance']."<br/>";
		echo "<br/>";
		echo "To checking account $CAN <br/>";
		echo "• Previous balance: $".(float)$CPRR['balance']."<br/>";
		echo "• New balance: $".(float)$CPOR['balance']."<br/>";
		echo "<br/>";

		// DEBUG SECTION
		if ($debug){
		echo "<br/>CHECKING PRE<br/> ";
		while($row = $stmt->fetch(PDO::FETCH_ASSOC)) {
			echo $row['id'].' '.$row['balance'];
			echo "<br/>";
		}
		echo "<br/>SAVING PRE<br/>";
		while($row = $stmt2->fetch(PDO::FETCH_ASSOC)) {
			echo $row['id'].' '.$row['balance'];
			echo "<br/>";
		}

		echo "<br/> ~~~~~~~~~~~~~~~~~~~~~~~~~~<br/> ";
		$stmt3 = $conn->query("SELECT balance as balance, account_number as id FROM saving WHERE account_number = $SAN");
		echo "<br/>SAVING POST<br/>";
		while($row = $stmt3->fetch(PDO::FETCH_ASSOC)) {
			echo $row['id'].' '.$row['balance'];
			echo "<br/>";
		}
		echo "<br/>CHECKING POST<br/>";
		$stmt4 = $conn->query("SELECT balance as balance, account_number as id FROM checking WHERE account_number = $CAN");
		while($row = $stmt4->fetch(PDO::FETCH_ASSOC)) {
			echo $row['id'].' '.$row['balance'];
			echo "<br/>";
		}
		}
		// END DEBUG

	} catch (PDOException $e) {
		// Should catch any errors
		echo "<br/>".$e->getMessage()."<br/><br/>";
		$conn->rollBack();
	}
}
$conn = null;
?>
