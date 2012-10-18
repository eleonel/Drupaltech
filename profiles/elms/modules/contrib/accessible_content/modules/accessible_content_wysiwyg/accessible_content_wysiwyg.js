if (Drupal.jsEnabled) {
  $(document).ready(function() {
    $('.ac_wysiwyg_link').click(function() {
      $.post($(this).attr('href'),
	      { html : $('#' + $(this).attr('textarea')).val(), guideline : $(this).attr('guideline')},
	      function(data) {
	        accessWin = window.open('', 'accessWin',  '');
	        accessWin.document.writeln(data);
	        accessWin.document.close();
	      });
      return false;
    });
  });
}