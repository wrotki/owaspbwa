<?php
/*
 * $RCSfile: Redirect.inc,v $
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
 * @version $Revision: 1.3 $ $Date: 2006/01/10 04:41:21 $
 * @package Permalinks
 * @subpackage UserInterface
 * @author Pierre-Luc Paour <gallery@paour.com>
 */

GalleryCoreApi::requireOnce('modules/permalinks/classes/PermalinksMapHelper.class');

/**
 * Perform the redirection
 *
 * @package Permalinks
 * @subpackage UserInterface
 *
 */
class RedirectController extends GalleryController {

    /**
     * @see GalleryController::handleRequest
     */
    function handleRequest(&$form) {
	$alias = GalleryUtilities::getRequestVariables('filename');
	if (empty($alias)) {
	    return array(GalleryCoreApi::error(ERROR_BAD_PARAMETER, __FILE__, __LINE__), null);
	}

	list ($ret, $itemId) = PermalinksMapHelper::fetchItemIdForAlias($alias);
	if ($ret) {
	    return array($ret->wrap(__FILE__, __LINE__), null);
	}

	GalleryUtilities::putRequestVariable('itemId', $itemId);

	$results = array('delegate' => array('view' => 'core.ShowItem'),
			 'status' => array(),
			 'error' => array());

	return array(null, $results);
    }
}
?>
