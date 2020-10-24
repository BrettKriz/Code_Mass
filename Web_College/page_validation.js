
/**
 * The method of displaying this information to the user can be altered to be made prettier if we want.
 *
 * @param msg   feedback message given by system.  Usually an error stacktrace
 */
function myAlert (msg) {
    BootstrapDialog.alert("The following form validation error occurred:\n" + msg);
}

// Test if the pre-decimal part of the input number is too large for the database column
function isShorterThan(candidate, value){

    var num = Math.ceil(Number(candidate));

    if (value < num.toString().length){
        return false;
    }

    return true;
}

// Value used for isLongerThan call
function isEmptyOrIsNonnegativeInteger (candidate, value) {

    if (candidate === "") {
        return true;
    }

    var num = Math.floor(Number(candidate));

    // if (num >= 0 && num == parseInt(Number(candidate), 10)){
    if (Number.isInteger(Number(candidate))){
        if(isShorterThan(candidate, value)){
            return true;
        }
    }

    return false;

}

function isEmptyOrIsInteger (candidate) {

    if (candidate === "") {
        return true;
    }

    var num = Math.floor(Number(candidate));

    // if (num == parseInt(Number(candidate), 10)){
    if(Number.isInteger(Number(candidate))){
        return true;
    }

    return false;

}

function isEmptyOrIsIntegerDegree (candidate) {

    if (candidate === "") {
        return true;
    }

    var num = Math.floor(Number(candidate));

    if (num >= 0 && num <= 360 && Number.isInteger(Number(candidate))){
        return true;
    }

    return false;

}

// maxlen used for isShorterThan
// neg: true if number can be negative
function isNumeric(val, maxlen, neg) {

    var len;
    var decimalPoint;
    var i;
    var j;
    var ch;

    val = "" + val;
    len = val.length;
    decimalPoint = false;

    for (i = 0; i < len; i++) {

        ch = val.charAt(i);

        if (ch === ".") {
            if (decimalPoint === true) {
                return false;
            }
            decimalPoint = true;
            if (!isShorterThan(val, maxlen)){
                return false;
            }
        } else if (ch === "-") {
            if (neg == false || i != 0){
                return false;
            }
        }
        else {
            for (j = 0; j < 10; j++) {
                if (ch === "0123456789".charAt(j)) {
                    break;
                }
            }
            if (j === 10) {
                return false;
            }
        }
    }
    if(!decimalPoint && !isShorterThan(val, maxlen)){
        return false;
    }

    return  true;

}

function isEmpty(canidate){
	if (candidate === "") {
        return true;
    }
	return false;
}

function isPH (candidate) {

    if (candidate === "") {
        return true;
    }

    var num = parseFloat("" + candidate);
    if (isNumeric(candidate, 2, false) === true && num >= 0 && num <= 14) {
        return true;
    }

    return false;

}

/**
 * Checks fields based on what page number is supplied.
 * Warns is invalid input is present
 *
 * @param curPage(int), totalQuestionPages(int)
 * @returns {boolean}
 */
function validatePage (curPage, totalQuestionPages){
	/* New Log Page */
    if (curPage === 0 || curPage === totalQuestionPages) {
        // The input types do that
    }

    /* Site Conditions */
    if (curPage === 1 || curPage === totalQuestionPages) {
		var secchi_depth 		= $("#secchi_depth").val();	// Needs Validation POSITIVE
        var air_temp 			= $("#air_temp").val();		// Needs Validation Clamping
        var water_temp 			= $("#water_temp").val();	// Needs Validation Clamping
		
		var h = 160
		var l = -1*h
		
		if (isEmptyOrIsNonnegativeInteger(do_1) === false) {
			myAlert("secchi depth is out of range");
            return false;
		}
		if (air_temp < l || air_temp > h) {
			myAlert("AIR TEMP is out of range...\n(Whats the future like?)");
            return false;
		}
		if (water_temp < l || water_temp > h) {
			myAlert("WATER TEMP is out of range");
            return false;
		}
    }

    /* Observations Page */
    if (curPage === 2 || curPage === totalQuestionPages) {
		// Currently not needed for any vars
    }

    /* Bacteria Data */
    if (curPage === 3 || curPage === totalQuestionPages) {

        // Not requested?
    }

    /* DO & pH Page */
    if (curPage === 4 || curPage === totalQuestionPages) {
		
		var do_1 = $("#do_1").val(); 						// Needs Validation
        var do_2 = $("#do_2").val();						// Needs Validation
        var ph_1 = $("#ph_1").val();						// Needs Validation PH
        var ph_2 = $("#ph_2").val();						// Needs Validation PH
		
		if (isEmptyOrIsNonnegativeInteger(do_1) === false) {
            myAlert("DO 1 level is not valid");
            return false;
        }
		if (isEmptyOrIsNonnegativeInteger(do_2) === false) {
            myAlert("DO 2 level is not valid");
            return false;
        }
        if (IspH(ph_1) === false) {
            myAlert("pH 1 level is not in the inclusive range of 0 to 14.");
            return false;
        }
        if (IspH(ph_2) === false) {
            myAlert("pH 2 level is not in the inclusive range of 0 to 14.");
            return false;
        }
    }

    /* Nitrogen Page */
    if (curPage === 5 || curPage === totalQuestionPages) {
        var nitrate_1 = $("#nitrate_1").val();				// Needs Validation    
        var nitrate_2 = $("#nitrate_2").val();				// Needs Validation
		
        var nitrite_1 = $("#nitrite_1").val();				// Needs Validation
        var nitrite_2 = $("#nitrite_2").val();				// Needs Validation

        var ammonia_1 = $("#ammonia_1").val();				// Needs Validation
        var ammonia_2 = $("#ammonia_2").val();				// Needs Validation
		
		if (isEmptyOrIsNonnegativeInteger(nitrate_1) === false) {
            myAlert("DO 1 level is not valid");
            return false;
        }
    }

    /* Phosphorus and Chloride Page*/
    if (curPage === 6 || curPage === totalQuestionPages) {
		var op_blank = $("#op_blank").val();					// Needs Validation?
        var op_1 = $("#op_1").val();							// Needs Validation
        var op_2 = $("#op_2").val();							// Needs Validation
        var chloride_blank = $("#chloride_blank").val();		// Needs Validation?
        var chloride_1 = $("#chloride_1").val();				// Needs Validation
        var chloride_2 = $("#chloride_2").val();				// Needs Validation
		
		if (isEmptyOrIsNonnegativeInteger(op_blank)) {
			myAlert("OP BLANK is not valid");
            return false;
		}
		if (isEmptyOrIsNonnegativeInteger(op_1)) {
			myAlert("OP 1 is not valid");
            return false;
		}
		if (isEmptyOrIsNonnegativeInteger(op_2)) {
			myAlert("OP 2 is not valid");
            return false;
		}
		if (isEmptyOrIsNonnegativeInteger(chloride_blank)) {
			myAlert("Cl BLANK is not valid");
            return false;
		}
		if (isEmptyOrIsNonnegativeInteger(chloride_1)) {
			myAlert("Cl 1 is not valid");
            return false;
		}
		if (isEmptyOrIsNonnegativeInteger(chloride_2)) {
			myAlert("Cl 2 is not valid");
            return false;
		}
    }

	return true // Everything normal
}

function getVolunteerCSV() {
	var volunteerCSV = "";
	// Get volunteers
	var volunteerCount = Math.abs(parseInt($("#volunteerCount").val())) + 1;
	for (let i = 0; i < volunteerCount; i++) {
		//@@@
		let volunteerName = $("#volunteer_name_" + i).val();
		volunteerName = fixComments(volunteerName); // RLP fixes 6-21-18
		let volunteerDate = $("#volunteer_date_" + i).val();
		let volunteerActivity = $("#volunteer_activity_" + i).val();
		volunteerActivity = fixComments(volunteerActivity); // RLP fixes 6-21-18
		let volunteerHours = Math.abs($("#volunteer_hours_" + i).val());

		volunteerCSV = volunteerCSV + volunteerDate +v+ volunteerName +v+ volunteerActivity +v+ volunteerHours + ",";
	}

	volunteerCSV 	= volunteerCSV.substring(0, volunteerCSV.length - 1); // remove last comma
	// ^ Please insert if(i < vC-1) block in the loop and remove this! ^
	return volunteerCSV;
}

/**
 * Collects data feilds and validates
 * Warns is invalid input is present
 *
 * @returns {string}
 */
function getCSV() {

		/*
			VALIDATION LOOP!
			Prevent 
		*/
		let flag = false;
		var csv = '';
		//while(flag === false){
			flag = validatePage(-1,-1);
			
		//}
		if (flag === false) {
			return CSV; // Do not pass go
		}
		
		/* New Log Page */
        var site_name 			= $("#site_name").val();	// 
        var wbid 				= $("#wbid").val();			// 
        var legal 				= $("#legal").val();		// 
        var county 				= $("#county").val();		// Needs Validation
        var date 				= $("#date").val();			// Needs Validation
        var latitude 			= $("#latitude").val();		// faked
        var longitude 			= $("#longitude").val();	// faked
        var site_time 			= $("#site_time").val();	// Needs Validation
        var sampler_1 			= $("#sampler_1").val();	// 
        var sampler_2 			= $("#sampler_2").val();	// 
		
        /* Site Conditions */
        var secchi_depth 		= $("#secchi_depth").val();	// Needs Validation POSITIVE
        var secchi_vis 			= $("#secchi_vis").is(":checked"); // RLP fixes 6-21-18.
        var air_temp 			= $("#air_temp").val();		// Needs Validation Clamping
        var air_temp_comments 	= " ";    // no longer desired by BThumb
        var water_temp 			= $("#water_temp").val();	// Needs Validation Clamping
        var water_temp_comments = " ";  // no longer desired by BThumb
		
        /* Observations Page */
        var clean 			= $("#clean").is(":checked");
        var manure 			= $("#manure").is(":checked");
        var unsightly 		= $("#unsightly").is(":checked");
        var foam 			= $("#foam").is(":checked");
        var detritus 		= $("#detritus").is(":checked");
        var trash 			= $("#trash").is(":checked");
        var sig_algae 		= $("#sig_algae").is(":checked");
        var fish_kill 		= $("#fish_kill").is(":checked");
        var dead_animals 	= $("#dead_animals").is(":checked");
        var iron_precip 	= $("#iron_precip").is(":checked");
        var siltation 		= $("#siltation").is(":checked");
        var flow_alter 		= $("#flow_alter").is(":checked");
        var habitat_alter 	= $("#habitat_alter").is(":checked");
        var oil_film 		= $("#oil_film").is(":checked");
        var odor 			= $("#odor").is(":checked");
        var exotic_spp 		= $("#exotic_spp").is(":checked");
        var cattle 			= $("#cattle").is(":checked");
        var other_obs 		= $("#other_obs").is(":checked");
        var obs_comments = $("#obs_comments").val(); // RLP fixes 6-21-18
        var site_obs_none = (clean | manure | unsightly | foam |
                detritus | trash | sig_algae | fish_kill | dead_animals |
                iron_precip | siltation | flow_alter | habitat_alter |
                oil_film | odor | exotic_spp | cattle | obs_comments) ? "Off" : "On";

        /* Scrub that shiiiiiiiitttttt */
        clean 			= clean ? "On" : "Off";
        manure 			= manure ? "On" : "Off";
        unsightly 		= unsightly ? "On" : "Off";
        foam 			= foam ? "On" : "Off";
        detritus 		= detritus ? "On" : "Off";
        trash 			= trash ? "On" : "Off";
        sig_algae 		= sig_algae ? "On" : "Off";
        fish_kill 		= fish_kill ? "On" : "Off";
        dead_animals 	= dead_animals ? "On" : "Off";
        iron_precip 	= iron_precip ? "On" : "Off";
        siltation 		= siltation ? "On" : "Off";
        flow_alter 		= flow_alter ? "On" : "Off";
        habitat_alter 	= habitat_alter ? "On" : "Off";
        oil_film 		= oil_film ? "On" : "Off";
        odor 			= odor ? "On" : "Off";
        exotic_spp 		= exotic_spp ? "On" : "Off";
        cattle 			= cattle ? "On" : "Off";
        other_obs 		= other_obs ? "On" : "Off";
        // obs_comments = obs_comments ? "On" : "Off"; // RLP fixes 6-21-18
		
        /* Bacteria Data */
        // TODO: We should contact Blue Thumb about this... its not in the CSV.
		
        /* DO & pH Page */
        var do_1 = $("#do_1").val(); 						// Needs Validation
        var do_1_comments = $("#do_1_comments").val();

        var do_ph_comments = $("#DO_pH_comments").val(); // RLP fixes 6-21-18

        var do_2 = $("#do_2").val();						// Needs Validation
        var do_2_comments = $("#do_2_comments").val();
        var ph_1 = $("#ph_1").val();						// Needs Validation PH
        var ph_1_comments = $("#ph_1_comments").val();
        var ph_2 = $("#ph_2").val();						// Needs Validation PH
        var ph_2_comments = $("#ph_2_comments").val();

        /* Nitrogen Page */
		var n_comments = $("#N_comments").val(); // RLP fixes 6-21-18
        var nitrate_1 = $("#nitrate_1").val();				// Needs Validation
        var nitrate_1_comments = $("#nitrate_1_comments").val();        
        var nitrate_2 = $("#nitrate_2").val();				// Needs Validation
        var nitrate_2_comments = $("#nitrate_2_comments").val();
		
        var nitrite_1 = $("#nitrite_1").val();				// Needs Validation
        var nitrite_1_comments = $("#nitrite_1_comments").val();
        var nitrite_2 = $("#nitrite_2").val();				// Needs Validation
        var nitrite_2_comments = $("#nitrite_2_comments").val();
		
        var ammonia_blank = " ";
        var ammonia_blank_comments = " ";
        var ammonia_1 = $("#ammonia_1").val();					// Needs Validation
        var ammonia_1_comments = $("#ammonia_1_comments").val();
        var ammonia_2 = $("#ammonia_2").val();					// Needs Validation
        var ammonia_2_comments = $("#ammonia_2_comments").val();
		
        /* Phosphorus and Chloride Page*/
        var op_blank = $("#op_blank").val();					// Needs Validation?
        var op_blank_comments = $("#op_blank_comments").val();

        var p_cl_comments = $("#P_Cl_comments").val(); // RLP fixes 6-21-18

        var op_1 = $("#op_1").val();							// Needs Validation
        var op_1_comments = $("#op_1_comments").val();
        var op_2 = $("#op_2").val();							// Needs Validation
        var op_2_comments = $("#op_2_comments").val();
        var chloride_blank = $("#chloride_blank").val();		// Needs Validation?
        var chloride_blank_comments = $("#chloride_blank_comments").val();
        var chloride_1 = $("#chloride_1").val();				// Needs Validation
        var chloride_1_comments = $("#chloride_1_comments").val();
        var chloride_2 = $("#chloride_2").val();				// Needs Validation
        var chloride_2_comments = $("#chloride_2_comments").val();
		
		
        var volunteerCSV = getVolunteerCSV();
       
		//}
        // Fix the comments so that they can have quotes and comman in them. // RLP fixes 6-21-18
        obs_comments 	= fixComments(obs_comments);

        do_ph_comments 	= fixComments(do_ph_comments);
        n_comments 		= fixComments(n_comments);

        p_cl_comments 	= fixComments(p_cl_comments);

        site_name 		= fixComments(site_name);
        sampler_1 		= fixComments(sampler_1);
        sampler_2 		= fixComments(sampler_2);
        wbid 			= fixComments(wbid);
        legal 			= fixComments(legal);
        county 			= fixComments(county);

		// Create CSV as one does...	
		csv =   site_name 		+v+ wbid				+v+ legal				+v+ county				+v+ date					+v+
				latitude		+v+ longitude			+v+ site_time			+v+ sampler_1			+v+ sampler_2				+v+
				weather			+v+ wind_spd			+v+ wind_dir			+v+ stage				+v+ stage_qual				+v+
				secchi_depth	+v+ secchi_vis			+v+ site_obs_none		+v+ clean				+v+ manure					+v+
				unsightly		+v+ foam				+v+ detritus			+v+ trash				+v+ sig_algae				+v+ 
				fish_kill		+v+ dead_animals		+v+ iron_precip			+v+ siltation			+v+ flow_alter				+v+ 
				habitat_alter	+v+ oil_film			+v+ odor				+v+ exotic_spp			+v+ other_obs				+v+
				cattle			+v+ obs_comments		+v+ air_temp			+v+ air_temp_comments	+v+ water_temp				+v+
				water_temp_comments	+v+ do_1			+v+ do_1_comments		+v+ do_2				+v+ do_2_comments			+v+
				ph_1			+v+ ph_1_comments		+v+ ph_2				+v+ ph_2_comments		+v+ do_ph_comments			+v+ 
				nitrate_1		+v+ nitrate_1_comments	+v+ nitrate_2			+v+ nitrate_2_comments	+v+ nitrite_1				+v+
				nitrite_1_comments	+v+ nitrite_2		+v+ nitrite_2_comments	+v+ ammonia_blank		+v+ ammonia_blank_comments	+v+
				ammonia_1		+v+ ammonia_1_comments	+v+ ammonia_2			+v+ ammonia_2_comments	+v+ n_comments				+v+
				op_blank		+v+ op_blank_comments	+v+ op_1				+v+ op_1_comments		+v+ op_2					+v+ 
				op_2_comments	+v+ chloride_blank		+v+ chloride_blank_comments	+v+ chloride_1		+v+ chloride_1_comments		+v+
				chloride_2		+v+ chloride_2_comments	+v+ p_cl_comments		+v+ volunteerCSV;

    return csv;
}

























