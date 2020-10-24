<?php
var_dump($_POST);


echo "<br/> Welcome";


echo $_POST["username"];

if ($_POST["department"] == "CS"){
	printf("<a href=\"http://www.cs.mtu.edu/\">Computer Science Home Page</a>");
	if($_POST["gender"] == "female"){
		echo"<br/> You got to join WICS!";
		printf("<a href=\"mailto:wics@mtu.edu\">Contact</a>");
	}
}else{
	echo "Would you like to switch to CS Department?<br/>";
}

date_default_timezone_set("America/Detroit");
echo "Today is".date('m.d.y');

?>
