<?php
/*
 * $RCSfile: module.inc,v $
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
 * @version $Revision: 1.31 $ $Date: 2006/03/22 03:52:36 $
 * @package uploadapplet
 * @author Pierre-Luc Paour <paour@users.sourceforge.net>
 */

class UploadAppletModule extends GalleryModule {

    function UploadAppletModule() {
	global $gallery;
	$this->setId('uploadapplet');
	$this->setName($gallery->i18n('Upload Applet'));
	$this->setDescription($gallery->i18n('Easy to use upload applet for media'));
	$this->setVersion('1.0.4');
	$this->setGroup('import', $gallery->i18n('Import'));
	$this->setCallbacks('getSiteAdminViews');
	$this->setRequiredCoreApi(array(7, 0));
	$this->setRequiredModuleApi(array(3, 0));
    }

    /**
     * @see GalleryPlugin::upgrade()
     */
    function upgrade($currentVersion) {
	global $gallery;

	list ($ret, $params) =
	    GalleryCoreApi::fetchAllPluginParameters('module', 'uploadapplet');
	if ($ret) {
	    return $ret->wrap(__FILE__, __LINE__);
	}

	if (!isset($params['uploaddefaultVariables'])) {
	    $ret = $this->setParameter('uploaddefaultVariables', '');
	    if ($ret) {
		return $ret->wrap(__FILE__, __LINE__);
	    }
	}

	if (!isset($params['uploadoverrideVariables'])) {
	    $ret = $this->setParameter('uploadoverrideVariables', 
		    'toSysOut=true|htmlEscapeCaptions=true');
	    if ($ret) {
		return $ret->wrap(__FILE__, __LINE__);
	    }
	}

	return null;
    }

    /**
     * @see GalleryModule::performFactoryRegistrations()
     */
    function performFactoryRegistrations() {
	$ret = GalleryCoreApi::registerFactoryImplementation(
	    'ItemAddPlugin', 'ItemAddUploadApplet', 'ItemAddUploadApplet',
	    'modules/uploadapplet/ItemAddUploadApplet.inc', 'uploadapplet', null);
	if ($ret) {
	    return $ret->wrap(__FILE__, __LINE__);
	}

	return null;
    }

    /**
     * @see GalleryModule::getSiteAdminViews()
     */
    function getSiteAdminViews() {
	return array(null,
		     array(array('name' => $this->translate('Upload Applet'),
				 'view' => 'uploadapplet.UploadAppletSiteAdmin')));
    }
}
?>
