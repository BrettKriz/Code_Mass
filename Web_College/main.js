/*
  main.js
  by Jake Mager 3/5/2018

  * Holds event listners for buttons
  * Dynamically navigate through pages
*/


// pages array
// This holds the order of the pages on the main app
var pages = ["home", "newLogStart", "siteConditons", "observations", "bacteria", "doAndph", "nitrogen", "phosphorus", "volunteers"];

// otherPages array
// This holds any other pages that are not in the main app
// like modals, help menus, etc.
var otherPages = [];




$( document ).ready(function() {

    // By Logan Wilson
	var v = "," // Named for visability, the delimiter in the CSVs
    var d = new Date();
    var day = d.getDate();
    var month = d.getMonth() + 1;
    var year = d.getFullYear();
    if (month < 10) month = "0" + month;
    if (day < 10) day = "0" + day;
    document.getElementById('date').value = year + "-" + month + "-" + day;

    //
    var hours = d.getHours();
    var minutes = d.getMinutes();
    if (hours < 10) hours = "0" + hours;
    if (minutes < 10) minutes = "0" + minutes;
    document.getElementById('site_time').value = hours+":"+minutes;


    navigator.geolocation.getCurrentPosition(function(position) {
        var lat = position.coords.latitude;
        var lon = position.coords.longitude;
        document.getElementById('latitude').value = lat;
        document.getElementById('longitude').value = lon;
    });

    // New Log button listner, just calls function for switchScreen
    $('#newLogBtn').on('click touch', function() {
        switchScreen("newLogStart");
    });

    // Forward navigation buttons listner
    // this gets the id of the current page which is the 3rd parent of the button
    // then increments the index of whereever that id is in the pages array
    $('.navForwardBtn').on('click touch', function() {
        var page = $(this).parent().parent().parent().get(0).id;
        var index = pages.indexOf(page) + 1;
        switchScreen(pages[index]);
    });

    // Back navigation buttons listner
    // same as forward btn listner ^^^^^
    $('.navBackBtn').on('click touch', function() {
        var page = $(this).parent().parent().parent().get(0).id;
        var index = pages.indexOf(page) - 1;
        switchScreen(pages[index]);
    });


    // Submit button listener
    // By Logan Wilson, Dustin Haxton
    $('#sendEmail').on('click touch', function() {

			var csv = getValidCSV();
			if (csv === '') {
				console.log("CSV returned as a blank string, aborting..");
				return;
			}
          console.log("CSV printout in sendMail");
          console.log(csv);

        $.ajax({
            type: 'POST',
            url: 'sendEmail.php',
            data: {'csv': csv},
        });


        alert("Submitted datasheet!")
        switchScreen(pages[0]);

    });

    $('a[data-toggle="tooltip"]').tooltip({
        animated: 'fade',
        placement: 'bottom',
    });




});

/*
 * Function for comments that might have commas or quotes in them
 * so they will work in the CSV.
 * Written by Robert Pastel 6-21-2018
 */
 function fixComments(comment) {
   /*
    * RlP fixes for comments so they can have commas and quotes in them
    *   1. need to replace any quote with double quoutes
    *   2. then need to put quotes around the comments
    */
    comment = comment.replace(/"/g,'""'); // double up the quotes
    comment = '"'+comment+'"'; // surround with quotes
    return comment;
 }

// function switchScreen
// screenToShow: string of next screen in pages array
// defaults to home page
function switchScreen(screenToShow) {
    closeNav();
    if (screenToShow.length === 0) {
        screenToShow = "home";
    }

    // loop through pages, hiding everything but screenToShow
    $.each(pages, function (index, page) {
        if (page == screenToShow) {
            $("#" + screenToShow).show();
        } else {
            $("#" + page).hide();
        }
    });

    // Home screen has white BG compared to rest of app
    if (screenToShow == "home") {
        $('body').css('background-color', '#fff');
        $('#main').css('background-color', '#fff');
        $('body').css('color', '#397bae');
    } else {
        $('body').css('background-color', '#397bae');
        $('#main').css('background-color', '#397bae');
        $('body').css('color', 'rgb(51, 51, 51)');
    }
}



// Side Navigation - Jake Mager
function openNav() {
    document.getElementById("mySidenav").style.width = "250px";
}

function closeNav() {
    document.getElementById("mySidenav").style.width = "0";
}
