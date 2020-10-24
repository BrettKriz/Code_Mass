<?php
session_start();

if(isset($_SESSION['views']))
	$_SESSION['views']=$_SESSION['views']+1;
else
	$_SESSION['views']=1;

echo "In this session, you are visiting this page for ".$_SESSION['views']."times";
?>

<br/>
Today's Temp is 75... Just Kidding!
