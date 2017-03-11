<?PHP
/**
 * This file contains the Menu.
 *
 * minicms (C) 2006 Marc-Oliver Pahl
 * http://minicms.m-o-p.de
**/

/** Define the sites:
  pageElement( $mnuEntry,
               $hierarchyDepth, -1 = invisible
               $fileName, 
               $title, 
               $metaKeywords, 
               $metaDesc )
               
  externalLinkElement( $mnuEntry, 
                       $hierarchyDepth, 
                       $title, 
                       $linkURL, 
                       $target='_blank' )
*/

// Setup
$hideNotActiveSubmenus = false; // if you want only currently active submenus to be open set the variable to true
$defaultPage = 1; /* Index of the default Page (shown if no address passed). */

        
$sites = Array( 
/* external Link */
                new externalLinkElement( 'Google', 
                                         0, 
                                         'Link zu Google.de', 
                                         'http://www.google.de',
                                         '_blank' ),
/* "normal" internal Page */
                new pageElement( 'Start',
                                 0,
                                 'start',
                                 'Demo-Startseite',
                                 'Stichw&ouml;rter &uuml;ber die Seite f&uuml;r Suchmaschinen',
                                 'Eine Beschreibung der Seite f&uuml;r Suchmaschinen' ),
                new pageElement( 'phpInSrc',
                                 0, 
                                 '__phpTest', 
                                 'Der PHP-Test' ),
/* "normal" internal Page that is NOT LISTED in the menu */
                new pageElement( 'Impressum', 
                                 -1, 
                                 'impressum', 
                                 'Das Impressum' )
                );
                

// if you want only currently active submenus to be open uncommet the following line:
//  require( 'includes/menuLogicCloseSubmenus.inc' ); // closes all not active submenus
?>