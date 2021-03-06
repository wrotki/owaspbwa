<?php
/*
* $RCSfile: UploadAppletSiteAdmin.inc,v $
*
* Gallery - a web based photo album viewer and editor
* Copyright (C) 2000-2006 Bharat Mediratta
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or (at
* your option) any later version.
*
* This program is distributed in the hope that it will be useful, but
* WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston, MA  02110-1301, USA.
*/
/**
 * @version $Revision: 1.4 $ $Date: 2006/02/26 21:17:03 $
 * @package UploadApplet
 * @author Pierre-Luc Paour <paour@users.sf.net>
 */

/**
 * @package UploadApplet
 * @subpackage UserInterface
 */
class UploadAppletSiteAdminController extends GalleryController {

    /**
     * @see GalleryController::handleRequest
     */
    function handleRequest($form) {
	$ret = GalleryCoreApi::assertUserIsSiteAdministrator();
	if ($ret) {
	    return array($ret->wrap(__FILE__, __LINE__), null);
	}

	$status = $error = array();
	if (isset($form['action']['add'])) {
	    $type = $form['variable']['type'];

	    if (empty($form[$type]['name']) || empty($form[$type]['value'])) {
		$error[] = "form[error][$type]";
	    } else {
		list ($ret, $variables) = $this->getVariables($type);
		if ($ret) {
		    return array($ret->wrap(__FILE__, __LINE__), null);
		}

		/* modify it */
		$variables[$form[$type]['name']] = $form[$type]['value'];

		/* serialize it again */
		$ret = $this->setVariables($type, $variables);
		if ($ret) {
		    return array($ret->wrap(__FILE__, __LINE__), null);
		}
	    }
	} else if (isset($form['action']['delete'])) {
	    $type = $form['variable']['type'];
	    if (empty($form['delete']['variable'])) {
		return array(GalleryCoreApi::error(ERROR_BAD_PARAMETER, __FILE__, __LINE__), null);
	    }

	    list ($ret, $variables) = $this->getVariables($type);
	    if ($ret) {
		return array($ret->wrap(__FILE__, __LINE__), null);
	    }
	    if (!isset($variables[$form['delete']['variable']])) {
		return array(GalleryCoreApi::error(ERROR_BAD_PARAMETER, __FILE__, __LINE__), null);
	    }

	    /* delete it */
	    unset($variables[$form['delete']['variable']]);

	    /* serialize it again */
	    $ret = $this->setVariables($type, $variables);
	    if ($ret) {
		return array($ret->wrap(__FILE__, __LINE__), null);
	    }
	}


	/* Figure out where to redirect upon success */
	$method = empty($error) ? 'redirect' : 'delegate';
	$results[$method]['view'] = 'core.SiteAdmin';
	$results[$method]['subView'] = 'uploadapplet.UploadAppletSiteAdmin';
	$results['status'] = $status;
	$results['error'] = $error;

	return array(null, $results);
    }

    function implode_with_key($assoc, $inglue = '=', $outglue = '&'){
	$return = '';
	if (!empty($assoc)) {
	    foreach ($assoc as $tk => $tv) {
		$return = ($return != '' ? $return . $outglue : '') .
		$tk . $inglue . $tv;
	    }
	}
	return $return;
    }

    function getVariables($type) {
	list ($ret, $variables) = GalleryCoreApi::getPluginParameter('module', 'uploadapplet',
		'upload' . $type . 'Variables');
	if ($ret) {
	    return array($ret->wrap(__FILE__, __LINE__), null);
	}

	/* unserialize the plugin parameter */
	if (!empty($variables)) {
	    $variables1 = explode('|', $variables);
	    foreach ($variables1 as $variable) {
		list ($key, $value) = explode('=', $variable);
		$variables2[$key] = $value;
	    }

	    return array(null, $variables2);
	}

	return array(null, null);
    }

    function setVariables($type, $variables) {
	$params = $this->implode_with_key($variables, '=', '|');

	return GalleryCoreApi::setPluginParameter('module', 'uploadapplet',
		'upload' . $type . 'Variables', $params);
    }
}

/**
 * @package UploadApplet
 * @subpackage UserInterface
 */
class UploadAppletSiteAdminView extends GalleryView {

    /**
    * @see GalleryView::loadTemplate
    */
    function loadTemplate(&$template, &$form) {
	$AdminUploadApplet = array();

	$ret = GalleryCoreApi::assertUserIsSiteAdministrator();
	if ($ret) {
	    return array($ret->wrap(__FILE__, __LINE__), null);
	}

	list ($ret, $params) = GalleryCoreApi::fetchAllPluginParameters('module', 'uploadapplet');
	if ($ret) {
	    return array($ret->wrap(__FILE__, __LINE__), null);
	}
	foreach ($params as $key => $value) {
	    $form[$key] = $value;
	}

	foreach (array('uploaddefaultVariables', 'uploadoverrideVariables') as $key) {
	    if (!empty($form[$key])) {
		$variablesArray = explode('|', $form[$key]);
		$variables = array();
		foreach ($variablesArray as $variable) {
		    $variables[] = $variable;
		}
		$form[$key] = $variables;
	    }
	}

	$template->setVariable('AdminUploadApplet', $AdminUploadApplet);
	$template->setVariable('controller', 'uploadapplet.UploadAppletSiteAdmin');
	return array(null,
		     array('body' => 'modules/uploadapplet/templates/UploadAppletSiteAdmin.tpl'));
    }
}
?>
