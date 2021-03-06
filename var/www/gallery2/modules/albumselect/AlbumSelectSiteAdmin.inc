<?php
/*
 * $RCSfile: AlbumSelectSiteAdmin.inc,v $
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
 * @version $Revision: 1.12 $ $Date: 2006/01/17 01:52:00 $
 * @package AlbumSelect
 * @author Alan Harder <alan.harder@sun.com>
 */

/**
 * @package AlbumSelect
 * @subpackage UserInterface
 */
class AlbumSelectSiteAdminController extends GalleryController {

    /**
     * @see GalleryController::handleRequest
     */
    function handleRequest($form) {
	$ret = GalleryCoreApi::assertUserIsSiteAdministrator();
	if ($ret) {
	    return array($ret->wrap(__FILE__, __LINE__), null);
	}

	$status = $error = array();
	if (isset($form['action']['save'])) {
	    foreach (array('sort', 'treeLines', 'treeIcons', 'treeCookies',
			   'treeExpandCollapse', 'treeCloseSameLevel') as $key) {
		$ret = GalleryCoreApi::setPluginParameter('module', 'albumselect', $key,
			      ($key == 'sort') ? $form['sort']
					       : ((isset($form[$key]) && $form[$key]) ? 1 : 0));
		if ($ret) {
		    return array($ret->wrap(__FILE__, __LINE__), null);
		}
	    }
	    $status['saved'] = 1;

	    /* Flush our cache */
	    GalleryDataCache::removeFromDisk(
		array('type' => 'module-data', 'module' => 'albumselect'));
	}

	$results = array('redirect' => array('view' => 'core.SiteAdmin',
					     'subView' => 'albumselect.AlbumSelectSiteAdmin'),
			 'status' => $status,
			 'error' => $error);

	return array(null, $results);
    }
}

/**
 * @package AlbumSelect
 * @subpackage UserInterface
 */
class AlbumSelectSiteAdminView extends GalleryView {

    /**
     * @see GalleryView::loadTemplate
     */
    function loadTemplate(&$template, &$form) {
	$ret = GalleryCoreApi::assertUserIsSiteAdministrator();
	if ($ret) {
	    return array($ret->wrap(__FILE__, __LINE__), null);
	}

	foreach (array('sort', 'treeLines', 'treeIcons', 'treeCookies',
		       'treeExpandCollapse', 'treeCloseSameLevel') as $key) {
	    if (!isset($form[$key])) {
		$form[$key] = false;
	    }
	}
	if ($form['formName'] != 'AlbumSelectSiteAdmin') {
	    $form['formName'] = 'AlbumSelectSiteAdmin';
	    list ($ret, $params) =
		GalleryCoreApi::fetchAllPluginParameters('module', 'albumselect');
	    if ($ret) {
		return array($ret->wrap(__FILE__, __LINE__), null);
	    }
	    foreach ($params as $key => $value) {
		$form[$key] = $value;
	    }
	}

	$template->setVariable('controller', 'albumselect.AlbumSelectSiteAdmin');
	return array(null,
		     array('body' => 'modules/albumselect/templates/AlbumSelectSiteAdmin.tpl'));
    }
}
?>
