
<form method="post" action="change_name.php">
<br/>
<input type="submit" name="ok" />
</form>

<select name="species">
	<option value=" ">All Pets</option>
	<option value="Cat">Cats</option>
	<option value="Dog">Dogs</option>
</select>
<br />
<select name="sex">
	<option value=" ">No preFURed Gender</option>
	<option value="M">Male</option>
	<option value="F">Female</option>
</select>
<br />
<br />
<select name="declawed">
	<option value=" ">No preFURence</option>
	<option value="F">Front Only</option>
	<option value="B">Back Only (Rare)</option>
	<option value="A">All</option>
</select>
<br />
<select name="color">
	<option value=" ">Any</option>
	<option value="orange">Orange</option>
	<option value="brown">Brown</option>
	<option value="grey">Grey</option>
	<option value="black">Black</option>
	<option value="white">White</option>
	<option value="calico">Calico</option>
	<option value="two tone">Two Tone</option>
	<option value="tortoiseshell"> Tortoise Shell</option>
</select>
<br />
<input type="checkbox" name="spayed" 	value="T" />Spayed/Nutered?<br />
<input type="checkbox" name="kids" 	value="T" />Good with kids?<br />
<input type="checkbox" name="smallpets" 	value="T" />Good with other pets?<br />
<input type="checkbox" name="cats" 	value="T" />Good with cats?<br />
<input type="checkbox" name="dogs" 	value="T" />Good with dogs?<br />
<input type="checkbox" name="friendly" 	value="T" />Is friendly?<br />
<br />
<input type="text" name="name" value="<?php echo $name;?>" />
<br />
<input type="text" name="shelter" value="<?php echo $shelter;?>" />

