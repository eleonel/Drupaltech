(function ($) {
$(document).ready(function(){
	// on click display / hide the purl box
	$('#edit-purl-workflow-purl-override').click(function(){
		// show if its checked for the override
	  if ($(this).attr('checked') == true) {
			$('#edit-purl-value-wrapper').css('display', 'block');
			$('#edit-purl-value').focus();
		}
		else {
			$('#edit-purl-value-wrapper').css('display', 'none');
		}
	});
});
})(jQuery);