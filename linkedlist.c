#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

/* Initialisation of the list
 * */
list_ptr list_new(void)
{
  list_ptr ma_liste = malloc(sizeof(struct list_node));
  ma_liste->next = NULL;
  return ma_liste;
}

/* Add a new cel to a list. 
 *  store the sprite_t to the new cel
 * */
list_ptr list_add(sprite_t sprite, list_ptr list)
{
  list_ptr ma_liste_ptr = malloc(sizeof(struct list_node));
  ma_liste_ptr->data = sprite;
  ma_liste_ptr->next = list;
  return ma_liste_ptr;
}

/* Return the length of a list
 * */
int list_length(list_ptr l)
{
  int taille_liste = 0;
  while(l){
    taille_liste++;
    l = l->next;
  }

  return taille_liste;
}

/* Reverse the order of a list
 * */
void list_reverse(list_ptr * l)
{
}

/* Copy a list to another one. 
 *  Return the new list
 * */
list_ptr list_clone(list_ptr list)
{
  return NULL;
}

/* Return true if the list is empty
 * */
bool list_is_empty(list_ptr l)
{
  if(l)
    return false;
  else
    return true;
}

/* Search the first cel of the list & 
 *  return the associated sprite 
 * */
sprite_t list_head_sprite(list_ptr l)
{
  return l->data;
}

/* Return the next cel in list or NULL
 * */
list_ptr list_next(list_ptr l)
{
  return NULL;
}

/* Search the last cel of a list 
 *  Remove the cel from the list
 *  Return the associated sprite
 * */
sprite_t list_pop_sprite(list_ptr * l)
{
  sprite_t mon_sprite;
  list_ptr ptr_local = list_new();
  ptr_local = *l;
  while(ptr_local->next != NULL){
    if(ptr_local->next->next == NULL){
      mon_sprite = ptr_local->data;
      ptr_local->next = NULL;
    }
    ptr_local = ptr_local->next;
  }
  return mon_sprite;
}

/* Remove the given cel in a list
 * */
void list_remove(list_ptr elt, list_ptr *l)
{
  list_ptr ptr_local = list_new();
  ptr_local = *l;
  while(ptr_local->next != NULL){
    if(ptr_local == elt){
      ptr_local = elt->next->next;
//      list_free(elt);
      break;
    }
    ptr_local = ptr_local->next;
  }
}

/* Wipe out a list.

 *  Don't forget to sprite_free() for each sprite
 * */
void list_free(list_ptr l)
{
  free(l);
}
