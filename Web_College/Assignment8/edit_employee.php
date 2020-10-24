
<?php
if(isset($_POST['edit'])){
	$name=$_POST['name'];
	$emp_no=$_POST['emp_no'];
}

        echo '<form method="post" action="change_name.php">';
        echo '<br/>';
        echo "Old name: ".$name;
        echo '<input type="text" name="newName" />';
        echo '<input type="submit" name="ok" />';
        echo '</form>';

?>

