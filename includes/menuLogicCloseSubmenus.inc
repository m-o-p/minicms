<?php
/**
 * This file sets all non open submenus of the menu to be invisible.
 *
 * minicms (C) 2010 Marc-Oliver Pahl
 * http://minicms.m-o-p.de
**/

// remove everything that is not open
$topMenuIDToBeOpen = '';
$found = false;
foreach( $sites as $value ){ // identify top menu to be open
  if ( $value->getHierarchyDepth() == 0 ) $topMenuIDToBeOpen = $value->getFileName(); // last top menu entry
  $found = ($value->getFileName()==$id2View);
  if ( $found ) break; // found current element
}

$closeChilds = true;
foreach( $sites as $value ){
  if ($value->getHierarchyDepth()==0) // top menu entry
    $closeChilds = ($value->getFileName()!=$topMenuIDToBeOpen) OR !$found;
  else if ($closeChilds) $value->setHierarchyDepth(-1); // set invisible
}
?>