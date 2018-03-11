/*
 * The rbtree implementation in this solution
 * is copied/modified from Fu Haiping's github
 * and some reference from linux kernel.
 * 
 * https://github.com/forhappy/rbtree
 * https://github.com/torvalds/linux
 *
 * Sweep Line Algorithm
 * http://www.csie.ntnu.edu.tw/~u91029/Point2.html
 * 
 * insert and search O(log(N))
 * sweep line ~ O(NlogN)
 */

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/* rbtree.h start */
/*
 * =============================================================================
 *
 *       Filename:  rbtree.h
 *
 *    Description:  rbtree(Red-Black tree) implementation adapted from linux
 *                  kernel thus can be used in userspace c program.
 *
 *        Created:  09/02/2012 11:36:11 PM
 *
 *         Author:  Fu Haiping (forhappy), haipingf@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

/*
  Red Black Trees
  (C) 1999  Andrea Arcangeli <andrea@suse.de>
  
  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  linux/include/linux/rbtree.h
  To use rbtrees you'll have to implement your own insert and search cores.
  This will avoid us to use callbacks and to drop drammatically performances.
  I know it's not the cleaner way,  but in C (not in C++) to get
  performances and genericity...
  Some example of insert and search follows here. The search is a plain
  normal search over an ordered tree. The insert instead must be implemented
  in two steps: First, the code must insert the element in order as a red leaf
  in the tree, and then the support library function rb_insert_color() must
  be called. Such function will do the not trivial work to rebalance the
  rbtree, if necessary.
*/
#define container_of(ptr, type, member) ({(type *)( (char *)ptr - offsetof(type,member) );})

struct rb_node {
    unsigned long  rb_parent_color;
    struct rb_node *rb_right;
    struct rb_node *rb_left;
} __attribute__((aligned(sizeof(long))));

struct rb_root {
    struct rb_node *rb_node;
};

#define rb_parent(r)   ((struct rb_node *)((r)->rb_parent_color & ~3))
#define RB_ROOT (struct rb_root) { NULL, }
#define rb_link_node(node, parent, rb_link) ({ \
    (node)->rb_parent_color = (unsigned long)parent; \
    (node)->rb_left = (node)->rb_right = NULL; \
    *rb_link = node; })

#define rb_color(r)   ((r)->rb_parent_color & 1)
#define rb_is_red(r)   (!rb_color(r))
#define rb_is_black(r) rb_color(r)
#define rb_set_red(r)  do { (r)->rb_parent_color &= ~1; } while (0)
#define rb_set_black(r)  do { (r)->rb_parent_color |= 1; } while (0)
#define rb_set_parent(rb, p) ({(rb)->rb_parent_color = ((rb)->rb_parent_color & 3) | (unsigned long)(p);})
/* rbtree.h end */

/* rbtree.c start */
/*
 * =============================================================================
 *
 *       Filename:  rbtree.c
 *
 *    Description:  rbtree(Red-Black tree) implementation adapted from linux
 *                  kernel thus can be used in userspace c program.
 *
 *        Created:  09/02/2012 11:38:12 PM
 *
 *         Author:  Fu Haiping (forhappy), haipingf@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

/*
  Red Black Trees
  (C) 1999  Andrea Arcangeli <andrea@suse.de>
  (C) 2002  David Woodhouse <dwmw2@infradead.org>
  
  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  linux/lib/rbtree.c
*/
void rb_rotate_left(struct rb_node *node, struct rb_root *root) {
    struct rb_node *right = node->rb_right;
    struct rb_node *parent = rb_parent(node);

    if ((node->rb_right = right->rb_left))
        rb_set_parent(right->rb_left, node);
    right->rb_left = node;

    rb_set_parent(right, parent);

    if (parent) {   
        if (node == parent->rb_left)
            parent->rb_left = right;
        else
            parent->rb_right = right;
    }
    else
        root->rb_node = right;
    rb_set_parent(node, right);
}

void rb_rotate_right(struct rb_node *node, struct rb_root *root) {
    struct rb_node *left = node->rb_left;
    struct rb_node *parent = rb_parent(node);

    if ((node->rb_left = left->rb_right))
        rb_set_parent(left->rb_right, node);
    left->rb_right = node;

    rb_set_parent(left, parent);

    if (parent) {   
        if (node == parent->rb_right)
            parent->rb_right = left;
        else
            parent->rb_left = left;
    }
    else
        root->rb_node = left;
    rb_set_parent(node, left);
}

void rb_insert(struct rb_node *node, struct rb_root *root) {
    struct rb_node *parent, *gparent;

    while ((parent = rb_parent(node)) && rb_is_red(parent)) {
        gparent = rb_parent(parent);

        if (parent == gparent->rb_left) {
            {
                register struct rb_node *uncle = gparent->rb_right;
                if (uncle && rb_is_red(uncle)) {
                    rb_set_black(uncle);
                    rb_set_black(parent);
                    rb_set_red(gparent);
                    node = gparent;
                    continue;
                }
            }

            if (parent->rb_right == node) {
                register struct rb_node *tmp;
                rb_rotate_left(parent, root);
                tmp = parent;
                parent = node;
                node = tmp;
            }

            rb_set_black(parent);
            rb_set_red(gparent);
            rb_rotate_right(gparent, root);
        } else {
            {
                register struct rb_node *uncle = gparent->rb_left;
                if (uncle && rb_is_red(uncle)) {
                    rb_set_black(uncle);
                    rb_set_black(parent);
                    rb_set_red(gparent);
                    node = gparent;
                    continue;
                }
            }

            if (parent->rb_left == node) {
                register struct rb_node *tmp;
                rb_rotate_right(parent, root);
                tmp = parent;
                parent = node;
                node = tmp;
            }

            rb_set_black(parent);
            rb_set_red(gparent);
            rb_rotate_left(gparent, root);
        }
    }

    rb_set_black(root->rb_node);
}

struct rb_node *rb_next(const struct rb_node *node) {
    struct rb_node *parent;

    if (rb_parent(node) == node)
        return NULL;

    if (node->rb_right) {
        node = node->rb_right;
        while (node->rb_left)
            node=node->rb_left;
        return (struct rb_node *)node;
    }

    while ((parent = rb_parent(node)) && node == parent->rb_right)
        node = parent;

    return parent;
}

struct rb_node *rb_prev(const struct rb_node *node) {
    struct rb_node *parent;

    if (rb_parent(node) == node)
        return NULL;

    if (node->rb_left) {
        node = node->rb_left;
        while (node->rb_right)
            node=node->rb_right;
        return (struct rb_node *)node;
    }

    while ((parent = rb_parent(node)) && node == parent->rb_left)
        node = parent;

    return parent;
}
/* rbtree.c end */

/*
 * search() and insert() method are modified from rbtree-tst.c 
 */

/*
 * =============================================================================
 *
 *       Filename:  rbtree-tst.c
 *
 *    Description:  rbtree testcase.
 *
 *        Created:  09/02/2012 11:39:34 PM
 *
 *         Author:  Fu Haiping (forhappy), haipingf@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */

#define NUM_NODES 200000
#define MASK 100000000
#define ABS(x) ((x) < 0 ? -(x) : (x))

struct mynode {
    struct rb_node rb;
    int x;
    int y;
};

struct rb_root mytree = RB_ROOT;

struct rb_node* search(struct rb_root *root, int x, int y) {
    struct rb_node *node = root->rb_node;

    while (node) {
        struct mynode *data = container_of(node, struct mynode, rb);

        if (x < data->x)
            if (node->rb_left)
                node = node->rb_left;
            else
                return node;
        else if (x > data->x)
            if (node->rb_right)
                node = node->rb_right;
            else
                return node;
        else if (y < data->y)
            if (node->rb_left)
                node = node->rb_left;
            else
                return node;
        else if (y > data->y)
            if (node->rb_right)
                node = node->rb_right;
            else
                return node;
        else
            return NULL;
    }
    return NULL;
}

int insert(struct rb_root *root, struct mynode *mn, int n, int x, int y) {
    struct rb_node **new = &(root->rb_node), *parent = NULL;

    while (*new) {
        struct mynode *data = container_of(*new, struct mynode, rb);

        parent = *new;
        if (x < data->x)
            new = &((*new)->rb_left);
        else if (x > data->x)
            new = &((*new)->rb_right);
        else if (y < data->y)
            new = &((*new)->rb_left);
        else if (y > data->y)
            new = &((*new)->rb_right);
        else
            return 0;
    }

    mn[n].x = x;
    mn[n].y = y;

    rb_link_node(&mn[n].rb, parent, new);
    rb_insert(&mn[n].rb, root);

    return 1;
}

int main(void) {
    struct mynode mn[NUM_NODES];
    int q, c, x, y, n = 0, m = 0, last_ans = 0, ans;
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d%d", &c, &x, &y);
        x = (last_ans + x) % MASK + 1;
        y = (last_ans + y) % MASK + 1;
        if (c == 1) {
            if (insert(&mytree, mn, n, x, y))
                n++;
        } else {
            struct rb_node *node = search(&mytree, x, y);
            if (node == NULL)
                last_ans = 0;
            else {
                struct mynode *data = container_of(node, struct mynode, rb);
                struct rb_node *tmp = node;
                last_ans = ABS(x - data->x) + ABS(y - data->y);
                while (tmp = rb_prev(tmp)) {
                    data = container_of(tmp, struct mynode, rb);
                    if (x - last_ans > data->x)
                        break;
                    ans = ABS(x - data->x) + ABS(y - data->y);
                    if (ans < last_ans)
                        last_ans = ans;
                }
                tmp = node;
                while (tmp = rb_next(tmp)) {
                    data = container_of(tmp, struct mynode, rb);
                    if (x + last_ans < data->x)
                        break;
                    ans = ABS(x - data->x) + ABS(y - data->y);
                    if (ans < last_ans)
                        last_ans = ans;
                }
            }
            printf("%d\n", last_ans);
        }
    }
    return 0;
}
