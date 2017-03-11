<?php
/**
* Definition of the pageElement.
*
* @author <Marc-Oliver Pahl>
* @version 1.0
* @date 2005/ 08/ 31
*/

/**
 * Representation of one of the systems elements.
 *
 * @param $mnuEntry The menu entry that belongs to the element (e.g. people).
 * @param $hierarchyDepth How deep in the hierarchy is the menu entry? (0 = top..n=most indented).
 * @param $fileName Filename in the source/ directory that contains the body (e.g. people.inc).
 * @param $title Title to be shown as browser's title. (e.g. peaople at the chair).
 * @param $metaKeywords The keywords that should be put into the according meta field (e.g. people chair computer science university tuebingen).
 * @param $metaDesc The keywords that should be put into the according meta field (e.g. People working at the chair).
 *
 * minicms (C) 2006 Marc-Oliver Pahl
 * http://minicms.m-o-p.de
 */
class pageElement{
  var $mnuEntry;
  var $hierarchyDepth;
  var $fileName;
  var $title;
  var $metaKeywords;
  var $metaDesc;
  
  /**
   * Constructor.
   *
   * @param $mnuEntry The menu entry that belongs to the element (e.g. people).
   * @param $hierarchyDepth How deep in the hierarchy is the menu entry? (-1=invisible, 0=leftmost..n=most indented).
   * @param $fileName Filename in the source/ directory that contains the body (e.g. people.inc).
   * @param $title Title to be shown as browser's title. (e.g. peaople at the chair).
   * @param $metaKeywords The keywords that should be put into the according meta field (e.g. people chair computer science university tuebingen).
   * @param $metaDesc The keywords that should be put into the according meta field (e.g. People working at the chair).
   *
   * @return New instance of pageElement.
   */
  function pageElement( $mnuEntry, $hierarchyDepth, $fileName, $title, $metaKeywords='', $metaDesc='' ){
    $this->mnuEntry = $mnuEntry; 
    $this->hierarchyDepth = $hierarchyDepth; 
    $this->fileName = $fileName; 
    $this->title = $title; 
    $this->metaKeywords = $metaKeywords; 
    $this->metaDesc = $metaDesc;
  }
  
  /**
   * Selector to get the menu entry.
   *
   * @return $this->mnuEntry
   */
  function getMnuEntry(){
    return $this->mnuEntry;
  }
  
  /**
   * Selector to get the hierarchy depth.
   *
   * @return $this->hierarchyDepth
   */
  function getHierarchyDepth(){
    return $this->hierarchyDepth;
  }
  /**
   * Selector to set the hierarchy depth.
   * This is only needed because of the invisible Menu entries...
   */
  function setHierarchyDepth( $value ){
    $this->hierarchyDepth = $value;
  }
  
  /**
   * Selector to get the filename.
   *
   * @return $this->fileName
   */
  function getFileName(){
    return $this->fileName;
  }
  
  /**
   * Selector to get the titley.
   *
   * @return $this->title
   */
  function getTitle(){
    return $this->title;
  }
  
  /**
   * Selector to get the meta keywords.
   *
   * @return $this->metaKeywords or if empty $this->title
   */
  function getMetaKeywords(){
    if ( $this->metaKeywords == '' ) return $this->title;
    return $this->metaKeywords;
  }  
  
  /**
   * Selector to get the meta description.
   *
   * @return $this->metaDesc or if empty $this->title
   */
  function getMetaDesc(){
    if ( $this->metaDesc == '' ) return $this->title;
    return $this->metaDesc;
  }  
}
?>