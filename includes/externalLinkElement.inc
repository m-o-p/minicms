<?php
/**
* Definition of the externalLinkElement.
*
* @author <Marc-Oliver Pahl>
* @version 1.0
* @date 2005/ 09/ 20
*
* minicms (C) 2006 Marc-Oliver Pahl
* http://minicms.m-o-p.de
*/

/**
 * Representation of an external link.
 *
 * @param $mnuEntry The menu entry that belongs to the element (e.g. people).
 * @param $hierarchyDepth How deep in the hierarchy is the menu entry? (0 = top..n=most indented).
 * @param $title The long description of the link target.
 * @param $linkURL The URLM to link to.
 * @param $newWin Should the link be opened in a new window (_blank)?.
 */
class externalLinkElement{
  var $mnuEntry;
  var $hierarchyDepth;
  var $title;
  var $linkURL;
  var $target;
  
  /**
   * Constructor.
   *
   * @param $mnuEntry The menu entry that belongs to the element (e.g. people).
   * @param $hierarchyDepth How deep in the hierarchy is the menu entry? (0=leftmost..n=most indented).
   * @param $title The long description of the link target.
   * @param $linkURL The URL to link to.
   * @param $target Should the link be opened in a new window (_blank)?.
   *
   * @return New instance of externalLinkElement.
   */
  function externalLinkElement( $mnuEntry, $hierarchyDepth, $title, $linkURL, $target='_blank' ){
    $this->mnuEntry = $mnuEntry; 
    $this->hierarchyDepth = $hierarchyDepth; 
    $this->title = $title;
    $this->linkURL = $linkURL;
    $this->target = $target; 
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
   * Selector to get the titley.
   *
   * @return $this->title
   */
  function getTitle(){
    return $this->title;
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
   * Selector to get the link's URL.
   *
   * @return $this->linkURL
   */
  function getLinkURL(){
    return $this->linkURL;
  }
  
  /**
   * Selector to get the link's target.
   *
   * @return $this->target
   */
  function getTarget(){
    return $this->target;
  }
}
?>