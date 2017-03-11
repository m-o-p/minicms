<?PHP
/**
 * This file contains the Menu Logic.
 *
 * minicms (C) 2010 Marc-Oliver Pahl
 * http://minicms.m-o-p.de
**/

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

require( 'menu.inc' ); // load menu array
                
// Search the array for $id2View ($_GET['site']) and build the $menuHTMLCode.
$currentPage = $sites[ $defaultPage ];
if ( isset($_GET['site']) ) $id2View = $_GET['site']; else $id2View = $currentPage->getFileName();
if ( substr( $id2View, -1 ) == '/' ) $id2View = substr( $id2View, 0, strlen($id2View)-1 ); // cut / at the end which comes from http redirects
$menuHTMLCode = '';

if (isset($hideNotActiveSubmenus) && $hideNotActiveSubmenus) require( 'includes/menuLogicCloseSubmenus.inc' ); // closes all not active submenus

// Since I want to put the upper Elements into the top row the get 
// collected into this array.
$upperElements = Array();
$currentMenuDepth = -1;
$wasFound = false;

foreach( $sites as $value ){
  if ( is_a($value, 'externalLinkElement' ) ){
    $menuHTMLCode .= '<li class="menu_ebene_'.$value->getHierarchyDepth().'">'.
                     '<a href="'.$value->getLinkURL().'" target="'.$value->getTarget().'" title="'.$value->getTitle().'">'.$value->getMnuEntry().'</a>'.
                     "</li>\n";
    continue;
  }
  
  $display = ( $value->getHierarchyDepth() != -1 );
  if ( ($value->getFileName() == $id2View) && $display )
    $menuHTMLCode .= '</ul><ul class="on">'."\n";

  if ( !$display )
    $value->setHierarchyDepth( 0 ); // don't display but put correctly inside the menu
  else
    $menuHTMLCode .= '<li class="menu_ebene_'.$value->getHierarchyDepth().'">'.
                     '<a href="/?site='.$value->getFileName().'" title="'.$value->getTitle().'">'.$value->getMnuEntry().'</a>'.
                     "</li>\n";
  
  // The followig code is for the hierarchical predecessors.
  if ( !$wasFound )
    if ( $currentMenuDepth >= $value->getHierarchyDepth() ){
     $upperElements[$value->getHierarchyDepth()] = $value;
     $currentMenuDepth = $value->getHierarchyDepth();
    }else{ 
      array_push( $upperElements, $value );
      $currentMenuDepth++;
    }
  
  if ( ($value->getFileName() == $id2View) ){
    if ( $display ) $menuHTMLCode .= "</ul><ul>\n";
    $currentPage = $value;
    $wasFound = true;
  }
}

if ( !$wasFound || !file_exists($srcDir.$currentPage->getFileName().$srcExt) ) 
  $currentPage = new pageElement( $ERROR['fileNotFoundMnu'], //$mnuEntry, 
                                  0, //$hierarchyDepth, 
                                  '404', //$fileName, 
                                  $ERROR['fileNotFound'] //$title, 
                                  //$metaKeywords='', 
                                  //$metaDesc='' 
                                 );

if ( !$wasFound ) $currentMenuDepth = 0;
// ensure the last entry is correct:
$upperElements[$currentMenuDepth] = $currentPage;
?>