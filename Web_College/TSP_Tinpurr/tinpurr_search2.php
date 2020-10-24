
<?php
	var_dump($_POST);
	// Connection Details!
	// @@@ Fill me out!
	$servername = "tinpurr.mtu.edu"; // <--- Change me!
	$username = "search";
	$password = "iwanttosearch";
	$dbname = "pet"; // Check that

	// SELECTBOXS: 	species, sex, color
	// BOOLS: 	spayed, kids, pets, friendly, cats, dogs, small pets
	// TEXTBOXS: 	name, shelter
	$SPECIES = $_POST["species"];
	$BREED = $_POST["breed"];
	$SEX = $_POST["sex"];
	$COLOR = $_POST["color"];
	// BOOLS
	$SPAYED = $_POST["spayed"]; // or fixed
	$KIDS = $_POST["kids"];
	$PETS = $_POST["smallpets"];
	$CATS = $_POST["cats"];
	$DOGS = $_POST["dogs"];
	$FRIENDLY = $_POST["friendly"];

	$PNAME = $_POST["name"];
	$SHELTER = $_POST["shelter"];
	$DECLAWED = $_POST["declawed"];

	$SPECICES_S = "";
	$BREED_S = "";
	$SEX_S =  "";
	$COLOR_S =  "";
	$SPAYED_S = "";
	$KIDS_S = "";
	$PETS_S = "";
	$FRIENDLY_S = "";
	$PNAME_S =  "";
	$SHELTER_S = "";
	$DECLAWED_S = "";

	// Change strings based of values
	if ($SPECIES != " "){
		$SPECICES_S = "AND species = '$SPECIES' ";
	}
	if ($BREED != " "){
		$BREED_S = "AND breed = '$breed' ";
	}
	if ($SEX != " "){
		$SEX_S = "AND sex = '$SEX' ";
	}
	if ($COLOR != " "){
		$COLOR_S = "AND '$COLOR' like color ";
	}
	if ($SPAYED != " "){
		$SPAYED_S = "AND fixed = '$SPAYED' ";
	}
	if ($KIDS != " "){
		$KIDS_S = "AND kids = '$KIDS' ";
	}
	if ($PETS != " "){
		$PETS_S = "AND pets = '$PETS' ";
	}
	if ($FRIENDLY != " "){
		$FRIENDLY_S = "AND friendly = '$FRIENDLY' ";
	}
	if ($PNAME != " "){
		$PNAME_S = "AND name = '$PNAME' ";
	}
	if ($SHELTER != " "){
		$SHELTER_S = "AND shelter = '$SHELTER' ";
	}
	if ($DECLAWED != " " ){
		$DECLAWED_S = "AND declawed = '$DECLAWED' ";
		// Since they want declawed, remove dogs and others
		$SPECICES_S = "AND species = 'Cat' ";
	}

	$WHERE_S = "WHERE fixed != NULL $SPECICES_S $SEX_S $COLOR_S $SPAYED_S $KIDS_S $PETS_S $FRIENDLY_S $PNAME_S $SHELTER_S;";

	// @@@IMPORTANT!
	// Destroy injection chars !
	// (OTHERWISE, KISS THE DATABASE GOODBYE!)
	$PNAME = str_replace("'","",$PNAME);
	$PNAME = str_replace("--","",$PNAME);
	$PNAME = str_replace(";","",$PNAME);

	$SHELTER = str_replace("'","",$SHELTER);
	$SHELTER = str_replace("--","",$SHELTER);
	$SHELTER = str_replace(";","",$SHELTER);

	$conn = null; // Make it known in this scope

	// Create connection first
	try {
		$conn = new PDO("mysql:host=$servername;dbname=$dbname", $username,$password);
		//echo "<br/> THIS .$conn.  <br/>";
		$conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
		//echo "<br/>Connection Established...";
	} catch (PDOException $e) {
		echo "<br/>Connection failed: " . $e->getMessage();
	}
	echo "<br/> ";

	// Construct search
	$expr_Search = "SELECT balance FROM saving $WHERE_S";
	$Search_res = null;
	$res_count = 0;
		// Run the query second
	try{
		$Search_res = $conn->query($expr_Search);
		// Now that we have the query
		// Manipulate the data
		$res_count = $Search_res->rowCount;

		if ($res_count <= 0){
			echo "<br/>No results found! Check your search terms!<br>"; 
			exit();
		}else{
			// Start echoing
			foreach ($Search_res as &$cur){
				// Grab a value
				echo $cur["name"];
				echo "<br/> ";
			}
			//echo "<br/> ";
		}

		
	} catch (PDOException $e) {
		echo $e->getMessage()."<br/>";
	}


	$conn = null;
?>
	
