<?php

function mda_settings_form() {
	// Data store
	$form['mda_orientation_email'] = array(
			'#type' => 'fieldset',
			'#title' => 'Message Email fiche d\'orientation',
			'#description' => 'Message email envoyé automatiquement au professionnel concerné lors de la création d\'une fiche contact.',
	);
	
	$form['mda_orientation_email']['mda_orientation_email_from'] = array(
			'#type' => 'textfield',
			'#title' => 'Email expéditeur',
			'#size' => 100,
			'#default_value' => variable_get('mda_orientation_email_from', variable_get('site_mail')),
	);
	$form['mda_orientation_email']['mda_orientation_email_subject'] = array(
			'#type' => 'textfield',
			'#title' => 'Titre du message',
			'#size' => 100,
			'#default_value' => variable_get('mda_orientation_email_subject', '[Tdbmda] : Nouvelle orientation de %contact à traiter'),
	);
	$url = $GLOBALS['base_url'];
	$default_body = "Bonjour,\n\n"
		. "Une demande d'orientation vous a été transmise.\n"
		. "Vous pouvez compléter la demande directement en ligne et/ou l'imprimer\nen cliquant sur le lien ci dessous :\n"
		. $url . "/fiche-orientation/orientation-de-%lastname-%firstname\n\n"
		. "Si le lien ne fonctionne pas, rendez vous dans l'onglet \"Demande 2015\"\nà l'adresse suivante :\n"
		. $url . "/demande2015";
	
	$form['mda_orientation_email']['mda_orientation_email_body'] = array(
			'#type' => 'textarea',
			'#title' => 'Corps du message',
			'#cols' => 150,
			'#rows' => 10,
			'#default_value' => variable_get('mda_orientation_email_body', $default_body),
	);
	
	return system_settings_form($form);
}