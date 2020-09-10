void quick_sort(struct node** head) {
	struct node* temp = *head;
	*head = NULL;

	while (temp) {
		struct node** lpointer = &temp;
		struct node** rpointer = &temp->next;
		bool swapped = false;

		while (*rpointer) {
			if ((*rpointer)->key <= (*lpointer)->key) {
				std::swap(*lpointer, *rpointer);
				std::swap((*lpointer)->next, (*lpointer)->next);
				lpointer = &(*lpointer)->next;
				swapped = true;
			}
			else lpointer = rpointer;
			rpointer = &(*rpointer)->next;
		}
		*rpointer = *head;

		if (swapped) {
			*rpointer = *lpointer;
			*lpointer = NULL;
		}
		else {
			*temp = **head;
			break;
		}
	}
}