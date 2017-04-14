#include "View.h"
#ifdef DEBUG
#include <assert.h>
#endif

void View::update(void* subject, UpdateType type)
{
	this->update((Drawable*)subject, type);
}

void View::update(Drawable* subject, UpdateType type)
{
#ifdef DEBUG
	// Make sure the subject is not null.
	assert(subject != nullptr);
#endif

	// Get the render level that the resource is at.
	int zIndex = subject->getZIndex();

	// Make the necessary layers.
	while (this->layers.size() <= zIndex) {
		layers.push_back(std::map<std::string, Drawable>());
	}

	// Get the current layer.
	auto layer = this->layers.at(zIndex);

	// Are we adding the subject for the first time?
	if (type == UpdateType::Attatch_Update) {
#ifdef DEBUG
		// The resource should not already be in there.
		assert(layer.count(subject->getResourceID()) != 0);
#endif

		// Create the entry, and add it into the layer.
		auto entry = std::pair<std::string, Drawable>(subject->getResourceID(), *subject);
		layer.insert(entry);
	}



	// Are we updating the subject?
	if (type == UpdateType::Notify_Update) {
#ifdef DEBUG
		// Make sure the resource exists.
		assert(layer.count(subject->getResourceID()));
#endif
		// Update the entry.
		auto entry = layer.find(subject->getResourceID());
		entry->second = *subject;
	}
}

void View::attachController(Controller* controller)
{
	this->controller = controller;
}